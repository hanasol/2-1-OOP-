#include <iostream>
#include <fstream>
using namespace std;
void strcpy_(char* str1, const char* str2);
int strcmp_(const char* str1, const char* str2);
int strlen_(const char* str);
void Search(int& flag, int& col, char* word, char* arr);
void Change(int flag, int col, char* word1, char* word2, char* arr);
void Insert(int col, char* word, char* arr);
void Delete(int flag, int col, char* word, char* arr);
#define max_row 1000
#define max_col 1000
int main() {
	ifstream fin;//���Ͽ��� ���ڿ��� �о���� ���� ifstream��ü
	char arr[max_row][max_col] = { 0, };//��� ���� �����ϴ� 2���� �迭
	char temp[300];//���Ͽ��� ���ڿ��� ������ char�� �迭
	int row = 0;//������ �� ��
	char menu[15];//�޴��� �Է¹��� char�� �迭

	while (1) {
		cin >> menu;
		if (0 == strcmp_(menu, "open")) {//open Ŀ�ǵ�
			char file_name[30];
			cin >> file_name;//���� �̸� �Է�
			fin.open(file_name);//�Է¹��� ������ ��
			while (fin.getline(temp, 300)) {//getline�� ���ؼ� temp�� ������ ������ �� ���徿 ����
				strcpy_(arr[row], temp);//2���� �迭�� �࿡ ������ ����
				row++;//�� ����
			}
		}
		else if (0 == strcmp(menu, "search")) {//search Ŀ�ǵ�
			char word[50] = { NULL };//ã�� �ܾ �Է¹��� �迭
			int num = 0;//ã�� �ܾ ����� ������ ����
			cin >> word;//�ܾ� �Է�
			for (int i = 0; i < row; i++) {
				int col = 0;//�� ���� ��
				int flag = 0;//�ܾ ã�Ҵ��� Ȯ���ϴ� ����
				Search(flag, col, word, arr[i]);//�ܾ� ��ġ
				if (flag == 1)//1�̶�� �ܾ ã�Ҵٴ� ���̹Ƿ�
					num++;//num����
			}
			cout << "===\'" << word << "\' search(" << num << ")===\n";
			for (int i = 0; i < row; i++) {
				int col = 0;
				int flag = 0;
				Search(flag, col, word, arr[i]);
				if (flag == 1) {//flag�� 1�̶�� ���ڿ��� ã��
					cout << "(" << i << ", " << col << ") ";//ã�� �ܾ��� ��� �� ���
				}
			}
			cout << "\n------------------------------\n";
		}
		else if (0 == strcmp_(menu, "change")) {//change Ŀ�ǵ�
			char word1[30];//�ٲ� �ܾ�
			char word2[30];//�ٲ� �ܾ�
			cin >> word1 >> word2;//�� �ܾ �Է¹���
			for (int i = 0; i < row; i++) {
				int col = 0;//�� ���� ��
				int flag = 0;//�ܾ ã�Ƽ� �ٲپ�� �ϹǷ� �ܾ ã�Ҵ��� Ȯ���ϴ� ����
				Search(flag, col, word1, arr[i]);//�ܾ� �˻�
				Change(flag, col, word1, word2, arr[i]);//�ܾ� ����
			}
			cout << "===change===\n";
			cout << word1 << " -> " << word2<<"\n";
			cout << "------------------------------\n";
		}
		else if (0 == strcmp_(menu, "insert")) {//insert Ŀ�ǵ�
			int row, col;//�ܾ ������ ��, ��
			char word[30];//������ �ܾ�
			cin >> row >> col >> word;//�� �� �ܾ� �Է�
			Insert(col, word, arr[row]);//�ش� ��� ���� �ܾ� ����
			cout << "===insert===\n";
			cout << word << " Inserted into (" << row << ", " << col << ")\n";
			cout << "------------------------------\n";
		}
		else if (0 == strcmp_(menu, "delete")) {//delete Ŀ�ǵ�
			char word[30];//������ �ܾ�
			cin >> word;
			for (int i = 0; i < row; i++) {
				int col = 0;//�� ���� ��
				int flag = 0;//�ܾ ã�Ƽ� �����ؾ� �ϹǷ� �ܾ ã�Ҵ��� Ȯ���ϴ� ����
				Search(flag, col, word, arr[i]);//�ܾ� �˻�
				Delete(flag, col, word, arr[i]);//�ܾ� ����
			}
			cout << "===delete===\n";
			cout << "Delete " << word << "\n";
			cout << "------------------------------\n";
		}
		else if (0 == strcmp_(menu, "save")) {//save Ŀ�ǵ�
			ofstream fout;//���� �ٲ� ������ ���Ͽ� �����ϱ� ���ؼ� ofstream��ü
			char file_name[20];//������ ���� �̸�
			cin >> file_name;
			fout.open(file_name);//������ ��
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < max_col && arr[i][j] != '\0'; j++)
					fout << arr[i][j];//��Ʈ������ ����Ǿ� ����� �Լ��� ���Ͽ� ����
				fout << "\n";
			}
			fout.close();//������ ����
			cout << "===save===\n";
			cout << "Save the file as \"" << file_name << "\"\n";
			cout << "------------------------------\n";
		}
		else if (0 == strcmp_(menu, "exit")) {
			cout << "Exit the program\n";
			fin.close();//open Ŀ�ǵ忡�� ������ ������ ����
			return 0;
		}
		else
			cout << "Invalid input\n";
	}

	fin.close();
}

void strcpy_(char* str1, const char* str2) {//str2�� ���ڿ��� str1�� �����ϴ� �Լ�
	int i = 0;
	while (str2[i] != NULL) {//str2�� NULL�� �ƴ϶�� �ݺ�
		str1[i] = str2[i];//str1�� i�ε����� str2�� i�ε����� �� ����
		i++;//i����
	}
	str1[i] = '\0'; // ���ڿ��� ���� �� ���ڸ� �߰�
}
int strcmp_(const char* str1, const char* str2) {//���ڿ��� ������ �����ִ� �Լ�
	int i = 0;
	while (str1[i] != NULL && (str1[i] == str2[i])) {//�� ���ڿ��� ���ڰ� ���� str1�� NULL�� �ƴ϶�� �ݺ�
		i++;
	}
	if (str1[i] - str2[i] == 0)//�� �ƽ�Ű ���� ���̰� 0�̶�� �� ���ڿ��� ����
		return 0;
	else if (str1[i] > str2[i])
		return 1;//str1�� str2���� ���������� �ڸ� 1��ȯ
	else
		return -1;//str1�� str2���� ���������� ���̸� -1��ȯ
}
int strlen_(const char* str) {//NULL�� ������ ���ڿ��� ���� ��ȯ
	int len = 0;//���ڿ��� ����
	int i = 0;
	while (str[i] != NULL) {//str�� NULL�� �ƴ϶�� �ݺ�
		len++;//�ݺ����� ���̰� 1�� ����
		i++;//i����
	}
	return len;//���ڿ��� ���� ��ȯ
}

void Search(int& flag, int& col, char* word, char* arr) {//���� ã�� �ܾ��� ���� �����ϴ� �Լ�
	int column = 0;
	int j = 0;
	int wordlen = strlen_(word);//ã�� �ܾ��� ���� ����
	for (int i = 0; i < max_col && arr[i] != '\0'; i++) {
		if (arr[i] == ' ') {//�����̶�� ���� ���ڷ� �Ѿ
			column++;
			continue;
		}
		else {//������ �ƴ϶�� �ܾ ��
			char temp[30] = { NULL };
			j = i;
			int k = 0;
			while (arr[j] != ' ' && arr[j] != '\0' && k < wordlen) {//���� ������ ������ ������, �ι��ڰ� �ƴ� �� ����, ã�� �ܾ��� ���̸�ŭ ��
				temp[k++] = arr[j++];//������ �ܾ ���ο� �迭�� ����
			}
			temp[k] = '\0';//���� �ι��ڸ� ������ ���ڿ��� ����
			if (0 == strcmp_(temp, word)) {//�� ���ڿ��� ���Ͽ� ���ٸ�
				col = column;//�ش� �ܾ��� ù �ε����� ����
				flag = 1;//flag�� 1�� ����
			}
			column++;//�� ����
		}
	}
}
void Change(int flag, int col, char* word1, char* word2, char* arr) {//word1 -> word2�� �ٲٴ� �Լ�
	if (flag == 0)//flag�� 0�̶�� �ٲ� �ܾ �ش� �࿡ �����Ƿ� ����
		return;
	else if(flag==1) {//flag�� 1�̶�� �ٲ� �ܾ �ش��࿡ �����Ƿ� ����
		int len1 = strlen_(word1);//�ٲ� �ܾ�
		int len2 = strlen_(word2);//�ٲ� �ܾ�
		int arrlen = strlen_(arr);//���� ����
		char temp1[200] = { NULL };//�ܾ ������ �չ���
		char temp2[200] = { NULL };//�ܾ ������ �޹���
		char newarr[300] = { NULL };//������
		int j = 0;
		int i;
		for (i = 0; i < col; i++) {//������ ó������ ���� ã�� �ܾ��� �ձ��� ����
			temp1[j] = arr[i];
			j++;
		}
		temp1[i] = '\0';//�ι��ڸ� �ٿ��� ���ڿ��� ����
		j = 0;
		for (i = col + len1; arr[i] != '\0'; i++) {//���忡�� ���� ã�� �ܾ��� �ں��� ������ ����
			temp2[j] = arr[i];
			j++;
		}
		temp2[i] = '\0';//�ι��ڸ� �ٿ��� ���ڿ��� ����
		int templen1 = strlen_(temp1);//�ܾ ������ �չ��� ����
		int templen2 = strlen_(temp2);//�ܾ ������ �޹��� ����
		int k = 0;
		for (int i = 0; i < templen1; i++) {//�չ����� ���ο� �迭�� ����
			newarr[i] = temp1[k];
			k++;
		}
		k = 0;
		for (int i = templen1; i < templen1 + len2; i++) {//�ٲ� �ܾ� ����
			newarr[i] = word2[k];
			k++;
		}
		k = 0;
		for (int i = templen1 + len2; i < templen1 + len2 + templen2; i++) {//�޹��� ����
			newarr[i] = temp2[k];
			k++;
		}
		newarr[templen1 + templen2 + len2] = '\0';//�չ��� ����+ �޹��� ����+ �ٲ� �ܾ��� ����= newarr�� ������ �ε���
		arr[arrlen] = ' ';//arr�� �� �� �ι��ڸ� �������� ��ü
		for (int i = 0; i < templen1 + templen2 + len2; i++) {
			arr[i] = newarr[i];//�ٽ� ������ �迭�� ����
		}
		arr[templen1 + templen2 + len2] = '\0';//�������� �ι��ڸ� �ٿ��� ���ο� ������ ���ڿ��� �ϼ�
	}
}
void Insert(int col, char* word, char* arr) {//�Է��� ��, ���� �ܾ �����ϴ� �Լ�
	int len = strlen_(word);//������ �ܾ��� ����
	int lenarr = strlen_(arr);//������ ����
	int j = 0;
	int i;
	char temp1[50] = { NULL };//�� ������ ������ �迭
	char temp2[50] = { NULL };//�� ������ ������ �迭
	char newarr[100] = { NULL };
	for (i = 0; i < col; i++){//���� ���� �� �������� ������ ����
		temp1[j] = arr[i];
		j++;
	}
	temp1[i] = '\0';//�������� �ι��ڸ� �Է��Ͽ� ���ڿ��� ����
	j = 0;
	for (i = col; arr[i] != NULL; i++) {//���� ���� �� �������� ������ ����
		temp2[j] = arr[i];
		j++;
	}
	temp2[i] = '\0';//�������� �ι��ڸ� �Է��Ͽ� ���ڿ��� ����
	int len1 = strlen_(temp1);//temp1�� ����
	int len2 = strlen_(temp2);//temp2�� ����
	for (int i = 0; i < len1; i++)//���ο� �迭�� �չ��� ����
		newarr[i] = temp1[i];
	int k = 0;
	for (int i = len1; i < len1 + len; i++) {//���ο� �迭�� ���� ������ �࿡ �ܾ� ����
		newarr[i] = word[k];
		k++;
	}
	k = 0;
	for (int i = len1 + len; i < len1 + len + len2; i++) {//�ܾ��� �ٷ� �ں��� �޹��� ����
		newarr[i] = temp2[k];
		k++;
	}
	newarr[len1 + len2 + len] = '\0';//�������� �ι��ڸ� �����Ͽ� ���ڿ��� ����
	arr[lenarr] = ' ';//arr�� ������ �ι��ڸ� �������� ��ü
	for (int i = 0; i < len1 + len2 + len; i++) {
		arr[i] = newarr[i];//������ ���忡 ���� ���� ������ ����
	}
	arr[len1 + len2 + len] = '\0';//�������� �ι��ڸ� �����Ͽ� ���ο� ������ ���ڿ��� ����
}
void Delete(int flag, int col, char* word, char* arr) {//�Է��� �ܾ �����ϴ� �Լ�
	int len = strlen_(word);//������ �ܾ��� ����
	if (flag == 0) {//flag�� 0�̶�� �ٲ� �ܾ �ش� �࿡ �����Ƿ� ����
		return;
	}
	else if (flag == 1) {////flag�� 1�̶�� �ٲ� �ܾ �ش� �������Ƿ� ����
		char temp[300] = { NULL };//�ٲ� �ܾ��� �ٷ� �޹����� ������ �迭
		int j = 0;
		int i;
		for (i = col + len; arr[i] != '\0'; i++) {
			temp[j] = arr[i];//temp�� ���� ���� �ܾ� ������ ������ ����
			j++;
		}
		for (int i = col; i < col + len; i++) {
			arr[i] = ' ';
		}//���� ������ �ܾ �������� �ٲ�
		temp[i] = '\0';//�������� �ι��� �����Ͽ� ���ڿ��� �ݵ�
		int templen = strlen_(temp);//temp�� ���� ����
		int k = 0;
		for (int i = col; i < col + templen; i++) {
			arr[i] = temp[k];//���� �ܾ��� ���� �ε������� temp�� �����Ͽ� �ܾ ���� ���ο� ������ ����
			k++;
		}
		arr[col + templen] = '\0';//���� �ܾ��� ���� �� + ������ ������ ����= �ܾ ���� ������ ��
		//���� ������ ������ �� �ε����� �ι��� ����
	}
}
