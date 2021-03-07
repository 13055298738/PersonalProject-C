#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>


using namespace std;
#define MAX_LENGTH 4<<10//���ʵ���󳤶�


typedef struct{
    string str;
    int wordcnt;
    int charcnt;
    int linecnt;
}word;


int number_of_words=0;//��¼����ͳ������
vector<string> raw_word;//��Դ�ı��еĵ��ʼ�
vector<word> word_statistics;//ͳ�ƽ����


/*�ֵ�����ȽϺ���*/
bool cmp_raw_word(const string &a,const string &b){return a<b;}


/*�ʻ���ִ�����������ȽϺ���*/
bool cmp_word_statistics(const word &a,const word &b){return a.wordcnt>b.wordcnt;}


/*���ȡ�Դ�����Դ�ļ�����Сд��ĸ������к��ּ��ַ�*/
bool skip(){ scanf("%*[^a-z||A-Z]"); return true;}


bool is_digit(char ch){
	return (ch>='0'&&ch<='9');
}

bool is_alpha(char ch){
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}


bool is_word(const char* str) {

	int char_num_count = 0;	// ��ͷ������ĸ�ĸ���

	if (is_digit(*str))		// �����һ���������ַ������ǵ��� 
		return false;

	// �����ַ��� 
	for (const char* p = str; *p != '\0'; p++) {

		if (is_alpha(*p))			// ������ַ�����ĸ��+1 
			char_num_count++;
		else if (char_num_count < 4)	// ������һ������ĸ�ַ�ʱ���������4�������ǵ��� 
			return false;

		if (char_num_count >= 4)
			return true;
	}
	return false;
}

int main(){

	
	/*���建��ռ�*/
	word w;
	char _word[MAX_LENGTH];
	
	
	vector<string>::iterator it,last;
	vector<word>::iterator wit;
	
	
	/*�ض����������� input.txt �ļ�,����ȡ input.txt �ļ�������Ӣ�ĵ���*/
	freopen("input.txt","r",stdin);
	while(skip()&&scanf("%[a-zA-Z]",_word)!=EOF){
		/*�����ʼ���*/
		if(is_word(_word)){
            number_of_words++;
	    /*��ֻ������ĸ��д�ĵ��ʵ�����ĸת����Сд*/
	        if(_word[1]!='\0'&&isupper(_word[0])&&islower(_word[1])){
			    _word[0]|=1<<5;
			}
	        raw_word.push_back(_word);
	  
        }
    }
	fstream fin;
	fin.open("input.txt");
    char ch;
    int charcnt=0;
    int linecnt=0;
    while(fin && fin.get(ch)){

        if(is_alpha(ch)||is_digit(ch)){
        	cout << ch;
        	charcnt++;
        	if(ch=='\n'){
   	 	       linecnt++;
	        }
	    }
   	    
    }
    fin.close();
   
   /*�ض���������� output.txt �ļ���������˵����Ϣ*/
    freopen("output.txt","w",stdout);
    printf("characters: %d\n",charcnt);
    printf("words: %d\n",number_of_words);
    printf("lines: %d\n",linecnt+1);
    


   /*��û�м�⵽����ʱ,�������򲢷�����ʾ��Ϣ*/
    if(!raw_word.size()){
       printf("There is no word in the \"in.txt\" or \"in.txt\" inexistence!\n");
       return 0;
    }


   /*�Ե��ʼ������ֵ������Ա���г��ִ���ͳ�Ʋ���*/
    sort(raw_word.begin(),raw_word.end(),cmp_raw_word);
    for(last=raw_word.begin(),it=raw_word.begin()+1;it!=raw_word.end();it++){
       if(*it!=*last){
          w.str=*last;
          w.wordcnt=it-last;
		  word_statistics.push_back(w);
          last=it;
		  
        }
    }


   /*�ֲ�����ѭ��ʱ���һ��δ�����뵥��*/
    w.str=*last;
    w.wordcnt=it-last;
    word_statistics.push_back(w);


   /*�Խ�������г��ִ����ؼ��ʽ�������*/
    sort(word_statistics.begin(),word_statistics.end(),cmp_word_statistics);
    bool b=false;
    for(wit=word_statistics.begin();wit!=word_statistics.end();wit++){
      /*Ϊ��֤ͳ��������,��ͳ������������е���*/
       if((*wit).wordcnt*1.0/number_of_words>=0.05||((*wit).wordcnt>=2&&(*wit).wordcnt*100.0/number_of_words>=0.01)){
      	  if(wit-word_statistics.begin()<10){
		  
            printf("%s: %d\n",((*wit).str).c_str(),(*wit).wordcnt);
            b=true;
            }

        }


    }


    return 0;
 
} 

	 
