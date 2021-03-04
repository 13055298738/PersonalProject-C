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
#define MAX_LENGTH 1<<10 //单词最大长度

class wordCount{
	private:
		typedef struct{
			string str;
			int wordcnt;
			int charcnt;
			int linecnt;
		}*word;

		int number_of_words;//记录单词统计总数
        vector<string> raw_word;//文本中的单词集
        vector<word> word_statistics;//统计结果集
	public:
		bool cmp_raw_word(const string &a,const string &b);
		bool cmp_word_statistics(const word &a,const word &b);
		bool skip();
		void wordCount();
		void characterAndLineCount(char *ch,int *charcnt,int *linecnt);
		void outPut(int *number_of_words,int *charcnt,int *linecnt);

};

#endif 
