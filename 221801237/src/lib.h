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
	public:
		bool cmp_raw_word(const string &a,const string &b);
		bool cmp_word_statistics(const word &a,const word &b);
		bool skip();
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
};

#endif 
