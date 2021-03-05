#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>


using namespace std;
#define MAX_LENGTH 1<<10//���ʵ���󳤶�


typedef struct{
    string str;
    int wordcnt;
    int charcnt;
    int linecnt;
}word;


int number_of_words=0;//��¼����ͳ������
vector<string> raw_word;//��Դ�ı��еĵ��ʼ�
vector<word> word_statistics(10);//ͳ�ƽ����


/*�ֵ�����ȽϺ���*/
bool cmp_raw_word(const string &a,const string &b){
    return a<b;
	}


/*�ʻ���ִ�����������ȽϺ���*/
bool cmp_word_statistics(const word &a,const word &b){
    return a.wordcnt>b.wordcnt;
	}


/*���ȡ�Դ�����Դ�ļ�����Сд��ĸ������к��ּ��ַ�*/
bool skip(){
    scanf("%*[^a-z||A-Z]"); return true;
	}


int main(){

	
	/*���建��ռ�*/
	word w;
	char _word[MAX_LENGTH];
	
	
	vector<string>::iterator it,last;
	vector<word>::iterator wit;
	
	
	/*�ض����������� in.txt �ļ�,����ȡ in.txt �ļ�������Ӣ�ĵ���*/
	freopen("in.txt","r",stdin);
	while(skip()&&scanf("%[a-zA-Z]",_word)!=EOF){
	      number_of_words++;
	      /*��ֻ������ĸ��д�ĵ��ʵ�����ĸת����Сд*/
	    if(_word[1]!='\0'&&isupper(_word[0])&&islower(_word[1])) _word[0]|=1<<5;
	    raw_word.push_back(_word);
    }
    /*�����ַ���������*/
    fstream fin;
	fin.open("in.txt");
    char ch;
    int charcnt=0;
    int linecnt=0;
    while(fin && fin.get(ch)){
   	   cout << ch;
   	   charcnt++;
   	   if(ch=='\n'){
   	 	   linecnt++;
	   }
    }
    fin.close();
    
    /*�ض���������� out.txt �ļ���������˵����Ϣ*/
    freopen("out.txt","w",stdout);
    printf("words: %d\n",number_of_words);
    printf("character: %d\n",charcnt);
    printf("line: %d\n",linecnt+1);
    


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
    
	 
