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

using namespace std;
#define MAX_LENGTH 1<<10 //单词最大长度

class wordCount{
	public:
		
};
typedef struct{
	string str;
	int cnt;
}; word


int number_of_words=0;//记录单词统计总数
vector<string> raw_word;//文本中的单词集
vector<string> word_statistics;//统计结果集


/*字典排序函数*/
bool cmp_raw_word(const string &a,const string &b){
	return a<b;
}


/*单词出现次数降序排序函数*/
bool cmp_word_statistics(const word &a,const word &b){
	return a.cnt>b.cnt;
}


/*虚读取以处理资源文件除大小写字母外的所有汉字及字符*/
bool skip(){
    scanf("%*[^a-z||A-Z]"); return true;
}

#endif 
