#pragma once
#ifndef LIB_H
#define LIB_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <ctime>
#include <cstdlib> 
#include <cmath>
#include <map>
#include <fstream>


using namespace std;
#define MAX_LENGTH 1<<10 //������󳤶�

class wordCount{
	private:
		typedef struct{
			string str;
			int wordcnt;
			int charcnt;
			int linecnt;
		}*word;

		int number_of_words;//��¼����ͳ������
        vector<string> raw_word;//�ı��еĵ��ʼ�
        vector<word> word_statistics;//ͳ�ƽ����
	public:
		bool cmp_raw_word(const string &a,const string &b);
		bool cmp_word_statistics(const word &a,const word &b);
		bool skip();
<<<<<<< HEAD
		void wordCount();
		void characterAndLineCount(char *ch,int *charcnt,int *linecnt);
		void outPut(int *number_of_words,int *charcnt,int *linecnt);

=======
		int wordCount();
		int characterCount();
		int lineCount();
		void outputFile();
		
		
	private:
		typedef struct{
			string str;
			int wordcnt;
			int charcnt;
			int linecnt;
		}*word;

		int number_of_words=0;//��¼����ͳ������
        vector<string> raw_word;//�ı��еĵ��ʼ�
        vector<word> word_statistics;//ͳ�ƽ����
>>>>>>> b9650582e2d7273c16f3cc3055801fee8bb796da
};

#endif 
