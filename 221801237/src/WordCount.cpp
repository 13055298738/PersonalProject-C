#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>


using namespace std;
#define MAX_LENGTH 1<<10//单词的最大长度


typedef struct{
    string str;
    int wordcnt;
    int charcnt;
    int linecnt;
}word;


int number_of_words=0;//记录单词统计总数
vector<string> raw_word;//资源文本中的单词集
vector<word> word_statistics(10);//统计结果集


/*字典排序比较函数*/
bool cmp_raw_word(const string &a,const string &b){
    return a<b;
	}


/*词汇出现次数降序排序比较函数*/
bool cmp_word_statistics(const word &a,const word &b){
    return a.wordcnt>b.wordcnt;
	}


/*虚读取以处理资源文件除大小写字母外的所有汉字及字符*/
bool skip(){
    scanf("%*[^a-z||A-Z]"); return true;
	}

