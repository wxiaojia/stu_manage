#include<iostream>
#include<string> 
#include<fstream>
#define M 100 
using namespace std;
typedef struct node *pointer; 
struct  node
{  
	string no;		//ѧ��
	string name;	//����
	string cla;	    //�༶
	string sex;		//�Ա� 
	string phone;	//�ֻ�����
	string sele;	//ѡ�޿γ�
	pointer next;
};
typedef pointer stu; 
/*�γ�*/
typedef struct  sub 
{ 	 string num;				//�γ̱��
	 string book;			//�γ���
	 string start;				//����ѧ��
}sub; 
 typedef struct  subject 
 {
	 sub data[M];  
	 int len;
 }subject; 
 /*���ļ��е���Ϣд�������У��γ�*/
subject readFile(subject L){
	ifstream cla("class.txt");
	cla.seekg(ios::beg);
	char s[100];
	cla.getline(s,100,'\n');
	while ( cla.getline(s,100,'\n') ){
		L.len++;
		char seg[] = "------"; 
        char charlist[4][50]={""};			/*ָ���ָ������ַ����洢��λ�ã����ﶨ���ά�ַ�������*/  
        int i =0;  
        char *substr= strtok(s, seg);		/*�����ֳɵķָ��,substrΪ�ָ���������ַ���*/  
        while (substr != NULL) {    
                strcpy(charlist[i],substr);/*���·ָ���������ַ���substr������Ҫ�洢��charlsit��*/  
                i++;  
				//	cout<<substr<<endl;
               substr = strtok(NULL,seg);  
        }   
		L.data[L.len].num=charlist[0];
		 L.data[L.len].book=charlist[1];
		L.data[L.len].start=charlist[2];
	}
	return L;
}
/*������д���ļ���*/
void writeFile(subject L){
	 ofstream clas("class.txt");
	 int a;
	 clas<<"�γ̱��------�γ���------����ѧ��"<<endl; 
	 for(a=1;a<=L.len;a++)  {
		 clas<<L.data[a].num<<"------"<<L.data[a].book<<"------"<<L.data[a].start<<endl;
	 }
}
 /*ѧ����Ϣ����Ŀ¼*/
 void stu_menu(){
	cout<<"ѧ����Ϣ����ϵͳ"<<endl;
	cout<<"1.���ѧ����Ϣ"<<endl;
    cout<<"2.ɾ��ѧ����Ϣ"<<endl;
	cout<<"3.�޸�ѧ����Ϣ"<<endl;
	cout<<"4.����ѧ����Ϣ"<<endl;
	cout<<"5.ѧ����Ϣ����"<<endl;
	cout<<"6.�γ���Ϣ"<<endl;
	cout<<"7.ѧ��ѡ��"<<endl;
	cout<<"8.���ѧ����Ϣ"<<endl;
	cout<<"9.�˳�"<<endl;
 }
 int length(stu s) {		//������ĳ��ȣ�����������Ԫ�صĸ���
	int j; 
	pointer p;
	j=0;
	p=s->next;				//���׽�㿪ʼ
	while(p!=NULL) {		//����⡢����
		j++; 
		p=p->next;
	}		
	return j;
}
 /*����Ų���*/
pointer get(stu head,int i) {	//�ҵ�i������Ԫ�أ�����ָ��ý���ָ��0��i��n
  int j;
  pointer p;
  if(i==0) return head;
  if(i<0) return NULL;			//λ�÷Ƿ����޴˽��
  j=0;							//������
  p=head->next;					//��ͷ��㣨0�ţ���ʼ����
  while(p!=NULL) {
    j++;
	if(j==i) break;
    p=p->next;					//δ����i�㣬����
  }
  return p;						//���ҵ���δ�ҵ��������
}
/*д���ļ���*/
void writeFile(stu s){
	int len=length(s);
	pointer q;
	ofstream stud("stu.txt");
	int a;
	stud<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
	for(a=1;a<=len;a++)  {
		q=get(s,a);
		stud<<q->no<<"------"<<q->name<<"------"<<q->cla<<"------"<<q->sex<<"------"<<q->phone<<"------"<<q->sele<<endl;
	}
}
/*��ʼ��*/
stu initlist(){
	pointer head;
	head=new node;
	head->next=NULL;
	return head;
}
//��ȡѧ���ļ�
stu readFile(){
	initlist();
	pointer s,head,rear;
	string ch;
	head=new node;
	rear=head;
	ifstream stu("stu.txt");
	stu.seekg(ios::beg);
	char c[100];
	stu.getline(c,100,'\n');
	while ( stu.getline(c,100,'\n') ){
		s=new node;
		char seg[] = "------";
		char charlist[50][50]={""};				/*ָ���ָ������ַ����洢��λ�ã����ﶨ���ά�ַ�������*/  
		int i =0;  
		char *substr= strtok(c, seg);			/*�����ֳɵķָ��,substrΪ�ָ���������ַ���*/  
		while (substr != NULL) {    
			strcpy(charlist[i],substr);		/*���·ָ���������ַ���substr������Ҫ�洢��charlsit��*/  
			i++;  
			//	cout<<substr<<endl;
			substr = strtok(NULL,seg);  
		}   
		s->no=charlist[0];
		s->name=charlist[1];
		s->cla=charlist[2];
		s->sex=charlist[3];
		s->phone=charlist[4];
		s->sele=charlist[5];
		rear->next=s;
		rear=s;
	}
	rear->next=NULL;
	return head;
}
/*��ѯ������ѧ��ѧ�ţ������*/
int search_no(stu head,string no) { //��λ����ֵΪx�Ľ���λ��
	int j;
	pointer p;
	j=0;						//������
	p=head->next;				//���׽�㿪ʼɨ��
	while(p!=NULL) {
		j++;
		if(p->no==no) break;		//�ҵ����˳�
		p=p->next;					//û�ҵ�������
	}
	if(p!=NULL) return j;		//�ҵ�x
	else return -1;				//û��x������ʧ��
}
/*��ѯ������ѧ�������������*/
int search_name(stu head,string name,int j){	//j������
	pointer p;
	p=get(head,j+1);				//�ӵ�i-1���ڵ㿪ʼɨ��
	while(p!=NULL) {
		j++;
		if(p->name==name) break;		//�ҵ����˳�
		p=p->next;						//û�ҵ�������
		
	}
	if(p!=NULL) return j;		//�ҵ�x
	else return -1;				//û��x������ʧ��
}
/*��ѯ������ѧ�������������*/
int search_phone(stu head,string phone,int j){	//j������
	pointer p;
	p=get(head,j+1);				//�ӵ�i-1���ڵ㿪ʼɨ��
	while(p!=NULL) {
		j++;
		if(p->phone==phone) break;		//�ҵ����˳�
		p=p->next;						//û�ҵ�������
		
	}
	if(p!=NULL) return j;		//�ҵ�x
	else return -1;				//û��x������ʧ��
}
/*��ѯ������ѧ���༶�������*/
int search_cla(stu head,string cla,int j){	//j������
	pointer p;
	p=get(head,j+1);				//�ӵ�i���ڵ㿪ʼɨ��
	while(p!=NULL) {
		j++;
		if(p->cla==cla) break;		//�ҵ����˳�
		p=p->next;						//û�ҵ�������
	}
	if(p!=NULL) return j;		//�ҵ�x
	else return -1;				//û��x������ʧ��
}
/*��ѯ������ѧ���Ա𣬲����*/
int search_sex(stu head,string sex,int j){	//j������
	pointer p;
	p=get(head,j+1);				//�ӵ�i���ڵ㿪ʼɨ��
	while(p!=NULL) {
		j++;
		if(p->sex==sex) break;		//�ҵ����˳�
		p=p->next;						//û�ҵ�������
	}
	if(p!=NULL) return j;		//�ҵ�x
	else return -1;				//û��x������ʧ��
}
/*��ѯ������ѧ��ѡ�޿Σ������*/
int search_selet(stu head,string selet,int j){	//j������
	pointer p;
	p=get(head,j+1);				//�ӵ�i���ڵ㿪ʼɨ��
	while(p!=NULL) {
		j++;
		if(p->sele==selet) break;		//�ҵ����˳�
		p=p->next;						//û�ҵ�������
	}
	if(p!=NULL) return j;		//�ҵ�x
	else return -1;				//û��x������ʧ��
}
/*1.���ѧ����Ϣ�����뵽��ͷ*/
void insert(stu head){
	string ch;
	int i;
	pointer s;
	s=new node;
	cout<<"������ѧ��ѧ��:";  
	cin>>ch;
	i=search_no(head,ch);
	while(i!=-1)  
    {  
       cout<<"��ѧ���Ѵ��ڣ�����������ѧ�ţ�";  
       cin>>ch;  
	   i=search_no(head,ch);
    }  
	s->no=ch;
	cout<<"������ѧ������:";  
	cin>>ch;
	s->name=ch;
	cout<<"������ѧ���༶(�磺15�����1��):";  
	cin>>ch;
	s->cla=ch;
	cout<<"������ѧ���Ա�(��д����/Ů):";  
	cin>>ch;
	s->sex=ch;
	cout<<"������ѧ���ֻ�����:";  
	cin>>ch;
	s->phone=ch;
	s->next=head->next;
	head->next=s;
	cout<<"��ӳɹ�"<<endl;
}
/*2.ɾ��Ŀ¼*/
void dele_menu(){
	cout<<"����***ɾ��ѧ����Ϣ����"<<endl;
	cout<<"1.ѧ��"<<endl;
    cout<<"2.����"<<endl;
	cout<<"3.�༶"<<endl;
	cout<<"4.����"<<endl;
 }
/*�����±����*/
void out_one(stu s,int a){
	pointer p;
	p=get(s,a);
	cout<<p->no<<"------"<<p->name<<"------"<<p->cla<<"------"<<p->sex<<"------"<<p->phone<<"------"<<p->sele;
	cout<<endl;
}
/*2.1��ѧ��ɾ��,*/
int deleByNo(stu s,string no){
	  int i=search_no(s,no);
	  pointer p,q;
	  q=get(s,i-1);	//�ҵ���i-1�����
	  if(q==NULL||q->next==NULL)  {cout<<"�����ڸ�ѧ�ŵ�ѧ��!";return 0;}
	  p=q->next;
	  q->next=p->next;
	  delete p;
	  cout<<"ɾ���ɹ�"<<endl;
	  return 1;
}
/*2.2.��ѧ����ɾ��*/
int deleByName(stu s,string name){
	pointer p,q;
	int i,j=0,n=0;					//j�Ǽ�����
	i=search_name(s,name,j);
	//	cout<<i<<endl;
	while(i!=-1){
		out_one(s,i);
		n++;
		j=i;
		i=search_name(s,name,j);
	}
	if(n==0){
		cout<<"�����ڸ�ѧ��";
	}
	else if(n==1){	 
	  q=get(s,j-1);
	  if(q==NULL)  {cout<<"�����ڸ�ѧ��";return 0;}
	  p=q->next;
	  q->next=p->next;
	  delete p;
	  cout<<"ɾ���ɹ�"<<endl;
	}
	else if(n>=2){
		cout<<"��"<<n<<"��ͬ��ѧ��,������Ϸ��ĳ��ֵ�ѧ��ѧ�ŵ�ѧ��ɾ�����ܽ���ɾ��"<<endl;
	}
	return 0;
}
/*2.3���༶ɾ��*/
int deleByCla(stu s,string cla){
	pointer p,q;
	int i,j=0,n=0;					//j�Ǽ�����
	i=search_cla(s,cla,j);
	while(i!=-1){
		 out_one(s,i);
		 q=get(s,i-1);
		 if(q==NULL||q->next==NULL)  {cout<<"ɾ��ʧ��(�Ƿ�ɾ��λ��)!\n";return 0;}
		 p=q->next;
		 q->next=p->next;
		 n++;
		 j=i-1;
		 i=search_cla(s,cla,j);
	}
	if(n==0){
		cout<<"�����ڸð༶"<<endl;
	}
	else {cout<<"ɾ���ɹ���һ��"<<n<<"��ͬѧ"<<endl;}
	return 0;
}
/*3.0��*/
void update_menu(){
	cout<<"�޸�ѧ��***��Ϣ����"<<endl;
	cout<<"1.����"<<endl;
    cout<<"2.�༶"<<endl;
	cout<<"3.�Ա�"<<endl;
	cout<<"4.�ֻ�����"<<endl;
	cout<<"5.ѡ�޿�"<<endl;
	cout<<"6.����"<<endl;
}
/*3.1�޸�����*/
stu updateName(stu S){
	pointer q;
	string no;
	string name;
	cout<<"������Ҫ�޸ĵ�ѧ��:";
	cin>>no;
	int b=search_no(S,no);
	if(b==-1) {cout<<"�����ڸ�ѧ��!"<<endl;}
	else{
		cout<<"������Ҫ�޸ĵ�����:";
		cin>>name;
		q=get(S,b);
		q->name=name;
		cout<<"�޸ĳɹ�"<<endl;
	}
	return S;
}
/*3.2�޸İ༶*/
stu updateCla(stu S){
	pointer q;
	string no;
	string cla;
	cout<<"������Ҫ�޸ĵ�ѧ��:";
	cin>>no;
	int b=search_no(S,no);
	if(b==-1) {cout<<"�����ڸ�ѧ��!"<<endl;}
	else{
		cout<<"������Ҫ�޸ĵİ༶:";
		cin>>cla;
		q=get(S,b);
		q->cla=cla;
		cout<<"�޸ĳɹ�"<<endl;
	}
	return S;
}
/*3.3�޸��Ա�*/
stu updateSex(stu S){
	pointer q;
	string no;
	string sex;
	cout<<"������Ҫ�޸ĵ�ѧ��:";
	cin>>no;
	int b=search_no(S,no);
	if(b==-1) {cout<<"�����ڸ�ѧ��!"<<endl;}
	else{
		cout<<"������Ҫ�޸ĵ��Ա�:";
		cin>>sex;
		q=get(S,b);
		q->sex=sex;
		cout<<"�޸ĳɹ�"<<endl;
	}
	return S;
}
/*3.4�޸ĵ绰*/
stu updatePhone(stu S){
	pointer q;
	string no;
	string phone;
	cout<<"������Ҫ�޸ĵ�ѧ��:";
	cin>>no;
	int b=search_no(S,no);
	if(b==-1) {cout<<"�����ڸ�ѧ��!"<<endl;}
	else{
		cout<<"������Ҫ�޸ĵĵ绰:";
		cin>>phone;
		q=get(S,b);
		q->phone=phone;
		cout<<"�޸ĳɹ�"<<endl;
	}
	return S;
}
/*6.5��*/
void out(subject L) {
	 int a;   
	 cout<<"�γ̱��------�γ���------����ѧ��"<<endl; 
	 for(a=1;a<=L.len;a++)  {
		 cout<<L.data[a].num<<"------";
		 cout<<L.data[a].book<<"------";
		 cout<<L.data[a].start<<endl;
	}
 }
/*4.0��ѯ*/
void search_menu(){
	cout<<"����**��Ϣ��ѯѧ��"<<endl;
	cout<<"1.ѧ��"<<endl;
	cout<<"2.����"<<endl;
	cout<<"3.�ֻ�����"<<endl;
	cout<<"4.����"<<endl;
}
/*4.1*/
void searchByno(stu S,string no){
	int s=search_no(S,no);
	out_one(S,s);
}
/*4.2�����������*/
void searchByname(stu s){
	string name;
	cout<<"�������ѯ��ѧ������:";
	cin>>name;
	int i,j=0,n=0;					//j�Ǽ�����
	i=search_name(s,name,j);
	while(i!=-1){
		out_one(s,i);
		j=i;
		n++;
		i=search_name(s,name,j);
	}
	cout<<"����"<<n<<"��ѧ��"<<endl;
}
/*4.3�����ֻ������ѯ*/
void searchByphone(stu s){
	string phone;
	cout<<"�������ѯ���ֻ�����:";
	cin>>phone;
	int i,j=0,n=0;					//j�Ǽ�����
	i=search_phone(s,phone,j);
	while(i!=-1){
		out_one(s,i);
		j=i;
		i=search_phone(s,phone,j);
	}
	cout<<"����"<<n<<"��ѧ��"<<endl;
}
/*5.����*/
void sort(){
	cout<<"����**��Ϣ����"<<endl;
	cout<<"1.ѧ��"<<endl;
    cout<<"2.�༶"<<endl;
	cout<<"3.�ֻ�����"<<endl;
	cout<<"4.����"<<endl;
}
/*8.4*/
void out(stu head) {
	pointer p;
	int len=length(head);
	if(len>0){
		p=head->next;			//���׽�㿪ʼɨ��
		cout<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
		while(p!=NULL) {
			cout<<p->no<<"------"<<p->name<<"------"<<p->cla<<"------"<<p->sex<<"------"<<p->phone<<"------"<<p->sele;
			cout<<endl;	
			p=p->next;		  	//pָ����һ�����
		}
		cout<<endl;	
	}
	cout<<"����"<<len<<"��ѧ��"<<endl;

}
/*5.1����ѧ������:ð������*/
stu Sort_no(stu s){
	int len=length(s);
	//	cout<<len<<endl;
	int flag;
	pointer p,q,l;
	if(len==0) {cout<<"û��ѧ��"<<endl;}
	else if(len==1) {out(s);}
	else if(len>=2){
		for(int i=1;i<=len;i++){	//��n-1��ɨ��
			flag=0;
			for(int j=len;j>=i+1;j--){
				p=get(s,j-1);
				q=p->next;
				if(q->no<p->no){
					flag=1;
					l=get(s,j-2);
					l->next=q;
					p->next=q->next;
					q->next=p;
				}
			}
			if(!flag) break;
		}			
	}
	return s;
}
/*5.2���ݰ༶����:ð������*/
stu Sort_cla(stu s){
	int len=length(s);
	//	cout<<len<<endl;
	int flag;
	pointer p,q,l;
	if(len==0) {cout<<"û��ѧ��"<<endl;}
	else if(len==1) {out(s);}
	else if(len>=2){
		for(int i=1;i<=len;i++){	//��n-1��ɨ��
			flag=0;
			for(int j=len;j>=i+1;j--){
				p=get(s,j-1);
				q=p->next;
				if(q->cla<p->cla){
					flag=1;
					l=get(s,j-2);
					l->next=q;
					p->next=q->next;
					q->next=p;
				}
			}
			if(!flag) break;
		}			
	}
	return s;
}
/*5.3���ݵ绰����:ð������*/
stu Sort_phone(stu s){
	int len=length(s);
	//	cout<<len<<endl;
	int flag;
	pointer p,q,l;
	if(len==0) {cout<<"û��ѧ��"<<endl;}
	else if(len==1) {out(s);}
	else if(len>=2){
		for(int i=1;i<=len;i++){	//��n-1��ɨ��
			flag=0;
			for(int j=len;j>=i+1;j--){
				p=get(s,j-1);
				q=p->next;
				if(q->phone<p->phone){
					flag=1;
					l=get(s,j-2);
					l->next=q;
					p->next=q->next;
					q->next=p;
				}
			}
			if(!flag) break;
		}			
	}
	return s;
}
/*6.�γ���Ϣ����Ŀ¼*/
  void sub_menu(){
	cout<<"�γ���Ϣ����"<<endl;
	cout<<"1.��ӿγ���Ϣ"<<endl;
    cout<<"2.ɾ���γ���Ϣ"<<endl;
	cout<<"3.�޸Ŀγ���Ϣ"<<endl;
	cout<<"4.���ҿγ���Ϣ"<<endl;
	cout<<"5.����γ���Ϣ"<<endl;
	cout<<"6.�˳�"<<endl;
 }
  /*6.4.1��ѯ�γ̱��*/
 int searchBynum(subject L,string num){
	int i,s=0;
	for(i=1;i<=L.len;i++){
		if(L.data[i].num==num)
		{s=i;break;}
	}
	return s;
 }
 /*6.4.2��ѯ�γ�����*/
 int searchByBook(subject L,string book){
	int i,b=0;
	for(i=1;i<=L.len;i++){
		if(L.data[i].book==book)
		{b=i;break;}
	}
	return b;
 }
/*6.1.����*/
subject insert(subject L){
	L.len++;
	int s=0,b=0;
	int n=L.len;
	cout<<"������γ̱��:";  
	cin>>L.data[n].num;
	s=searchBynum(L,L.data[n].num);
	while(s!=n)  
    {  
       cout<<"�ñ���Ѵ��ڣ�������������ţ�";  
       cin>>L.data[n].num;  
	   s=searchBynum(L,L.data[n].num);
    }  
	cout<<"������γ���:";  
	cin>>L.data[n].book;
	b=searchByBook(L,L.data[n].book);
	while(b!=n)  
    {  
       cout<<"�ÿγ����Ѵ��ڣ������������γ�����";  
       cin>>L.data[n].book;  
	   b=searchByBook(L,L.data[n].book);
    }  
	cout<<"�����뿪��ѧ��:";  
	cin>>L.data[n].start;
	return L;
}
/*6.2.ɾ��Ŀ¼*/
void delecla_menu(){
	cout<<"����***ɾ���γ���Ϣ����"<<endl;
	cout<<"1.�γ̱��"<<endl;
    cout<<"2.�γ���"<<endl;
	cout<<"3.�˳�"<<endl;
 }
/*6.6.0ɾ����󲿷�ǰ*/
subject dele(subject L,int s){
	int j;
	for(j=s+1;j<=L.len;j++){
		L.data[j-1]=L.data[j];
	}
	L.len--;
	cout<<"ɾ���ɹ�;"<<endl;
	return L;
}
/*6.2.1���γ̱��ɾ��*/
subject deleByNum(subject L,string i){
	int s;
	if(L.len==0) {cout<<"��գ�����ɾ��"<<endl;}
	else{
		s=searchBynum(L,i);
		cout<<s;
		if(s<1||s>L.len) {cout<<"�Ҳ����˿γ�"<<endl;}
		else{
			L=dele(L,s);
		}
	}
	return L;
}

/*6.2.2���γ���ɾ��*/
subject deleByName(subject L,string book){
	int b=0;
	b=searchByBook(L,book);
	if(b==0){cout<<"�����ڴ˿γ�!!"<<endl;}
	else{
		L=dele(L,b);
	}
	return L;
}
/*6.3.0��*/
void updatecla_menu(){
	cout<<"�޸Ŀγ�***��Ϣ����"<<endl;
	cout<<"1.�γ���"<<endl;
    cout<<"2.����ѧ��"<<endl;
	cout<<"3.�˳�"<<endl;
}
/*6.3.1�޸Ŀγ�*/
subject updateName(subject L){
	string num;
	string book;
	cout<<"������Ҫ�޸ĵı��:";
	cin>>num;
	int n=searchBynum(L,num);
	if(n==0) {cout<<"�����ڸÿγ̱�š�"<<endl;}
	else{
		cout<<"������Ҫ�޸ĵĿγ�:";
		cin>>book;
		int b=searchByBook(L,book);
		if(b==0) {L.data[n].book=book;cout<<"�޸ĳɹ�"<<endl;}
		else cout<<"�ÿγ��Ѿ����ڣ����Ϊ"<<L.data[n].num<<endl;
	}
	return L;
}
/*6.3.2 �޸Ŀ���ѧ��*/
subject updateStart(subject L){
	string num,start;
	cout<<"������Ҫ�޸ĵı��:";
	cin>>num;
	cout<<"������Ҫ�޸ĵĿ���ѧ��:";
	cin>>start;
	int n=searchBynum(L,num);
	L.data[n].start=start;
	cout<<"�޸ĳɹ�"<<endl;
	return L;
}
/*6.4��ѯ*/
void searchcla_menu(){
	cout<<"����**��Ϣ��ѯ�γ̹���"<<endl;
	cout<<"1.�γ̱��"<<endl;
	cout<<"2.�γ���"<<endl;
    cout<<"3.����ѧ��"<<endl;
	cout<<"4.�˳�"<<endl;
}
/*6.4.0 ���ݱ����*/
void out_one(subject L,int num){
	cout<<"�γ̱��------�γ���------����ѧ��"<<endl; 
	cout<<L.data[num].num<<"------";
	cout<<L.data[num].book<<"------";
	cout<<L.data[num].start<<endl;
}
/*6.4.1 ���ݱ�Ų�*/
subject search_num(subject L){
	string num;
	int n;
	cout<<"�������ѯ�ı��:";
	cin>>num;
	n=searchBynum(L,num);
	cout<<n;
	if(n==0) cout<<"�����ڸñ��;"<<endl; 
	else out_one(L,n);	
	return L;
}
/*6.4.2 ���ݿγ�����*/
subject search_name(subject L){
	string book;
	int b;
	cout<<"�������ѯ�Ŀγ���:";
	cin>>book;
	b=searchByBook(L,book);
	if(b==0) cout<<"�����ڸÿγ���;"<<endl;
	else out_one(L,b);
	return L;
}
/*6.4.3 ���ݿ���ѧ�ڲ�*/
subject search_start(subject L){
	string start;
	cout<<"�������ѯ�Ŀ���ѧ��:";
	cin>>start;
	int flag=0;
	for(int i=1;i<=L.len;i++){
		if(L.data[i].start==start)
			{out_one(L,i);flag=1;}	
	}
	if(flag==0) cout<<"�����ڸ�ѧ�ڵĿγ�"<<endl;
	return L;
}
/*7. ѧ��ѡ��*/
 stu selectcla(stu S,subject L){
	pointer p;
	int n;
    string no,num;
 	cout<<"������ѡ��ѧ��ѧ�ţ�";
 	cin>>no;
 	int s=search_no(S,no);
 	if(s==0) cout<<"�����ڸ�ѧ��"<<endl;
 	else{
 		out(L);
	 	cout<<"������ѡ�εı�ţ�";
		cin>>num;
		n=searchBynum(L,num);
		if(n==0) cout<<"�����ڸÿγ̱��;"<<endl; 
		else {
			p=get(S,s);
			p->sele=num;
			cout<<"ѡ�γɹ�"<<endl;
		}	
	}
 	return S;
 }
/*8.���*/
void print(){
	cout<<"����**��Ϣ���"<<endl;
    cout<<"1.�༶"<<endl;
	cout<<"2.�Ա�"<<endl;
	cout<<"3.ѡ�޿�"<<endl;
	cout<<"4.ȫ��"<<endl;
	cout<<"5.����"<<endl;
}
/*8.1���ݰ༶���*/
void searchBycla(stu s){
	string cla;
	cout<<"�������ѯ�İ༶:";
	cin>>cla;
	int i,j=0,n=0;					//j�Ǽ�����
	i=search_cla(s,cla,j);
	if(n==0&&i!=-1){
		cout<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
	}
	while(i!=-1){
		out_one(s,i);
		j=i;
		n++;
		i=search_cla(s,cla,j);
	}
	cout<<"����"<<n<<"��ѧ��"<<endl;
}
/*8.2�����Ա����*/
void searchBysex(stu s){
	string sex;
	cout<<"�������ѯ���Ա�:";
	cin>>sex;
	int i,j=0,n=0;					//j�Ǽ�����
	i=search_sex(s,sex,j);
	if(n==0&&i!=-1){
		cout<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
	}
	while(i!=-1){
		out_one(s,i);
		j=i;
		n++;
		i=search_sex(s,sex,j);
	}
	cout<<"����"<<n<<"��ѧ��"<<endl;
}
/*8.3����ѡ�޿����*/
void searchByselect(stu s){
	string selet;
	cout<<"�������ѯ�İ༶:";
	cin>>selet;
	int i,j=0,n=0;					//j�Ǽ�����
	i=search_selet(s,selet,j);
	if(n==0&&i!=-1){
		cout<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
	}
	while(i!=-1){
		out_one(s,i);
		j=i;
		n++;
		i=search_selet(s,selet,j);
	}
	cout<<"����"<<n<<"��ѧ��"<<endl;
}
void main(){
	stu s;
	s=readFile();
	int x,j;
	string no,num;
	subject L;  
	L.len=0;
	L=readFile(L);
	while(1){
		stu_menu();
		cout<<endl;
		cout<<"������Ҫʵ�ֵĹ��ܣ�";
		cin>>x;
		switch(x){
			case 1:{  insert(s);cout<<endl;writeFile(s);break;  }
			case 2:{	dele_menu();
						int y;
						char con='y';
						string name;
						string cla;
						while(con=='y'){
							cout<<"�������й�ɾ���Ĺ���:";
							cin>>y;
							//1��ѧ�ţ�2���� 3.�༶  4.ѡ�޿�
							if(y==1) {cout<<"������Ҫɾ��ѧ����ѧ��:";cin>>no;j=deleByNo(s,no);}
							else if(y==2) {cout<<"������Ҫɾ����ѧ����:";cin>>name;j=deleByName(s,name);}
							else if(y==3) {cout<<"������Ҫɾ����ѧ���İ༶��";cin>>cla;j=deleByCla(s,cla);}
							else if(y==4) break;	
							cout<<endl;
							cout<<"�Ƿ����ɾ����y:����,���������������һ��):";
							cin>>con;
							cout<<endl;
						}
						writeFile(s);
						break;
					}
			case 3:{	update_menu();
						int y;
						char con='y';
						while(con=='y'){
							cout<<"�������й��޸ĵĹ���:";
							cin>>y;
//							//1���� 2.�༶ 3.�Ա� 4.�绰 
							if(y==1)	s=updateName(s);
							else if(y==2) s=updateCla(s);
							else if(y==3) s=updateSex(s);
							else if(y==4) s=updatePhone(s);
							else if(y==5) s=selectcla(s,L);
							else if(y==6) break;	
							cout<<endl;
							cout<<"�Ƿ�����޸ģ�y:����,�����������һ��):";
							cin>>con;
							cout<<endl;
						}
						writeFile(s);
						break;
					}
			case 4:{	search_menu();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"�������йز�ѯ�Ĺ���:";
							cin>>y;
							// 1.ѧ��  2.����  3.�绰����
							if(y==1) {cout<<"������Ҫ��ѯѧ����ѧ��:";cin>>no;searchByno(s,no);}
							else if(y==2) searchByname(s);
							else if(y==3) searchByphone(s);
							else if(y==4) break;
							cout<<endl;
							cout<<"�Ƿ������ѯ��y:����,�����������һ��):";
							cin>>con;
							cout<<endl;
						}
						break;
				   }
			case 5:{	sort();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"�������й�����Ĺ���:";
							cin>>y;
							// 1.ѧ��  2.�༶  3.�绰
							if(y==1) {s=Sort_no(s);out(s);}
							else if(y==2) {s=Sort_cla(s);out(s);}
							else if(y==3) {s=Sort_phone(s);out(s);}
							else if(y==4) break;
							cout<<endl;
							cout<<"�Ƿ�������������y:����,�����������һ��):";
							cin>>con;
							cout<<endl;
						}
						break;
			}
			case 6:{	sub_menu();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"�������йؿγ���Ϣ�Ĺ���:";
							cin>>y;
							// 1.���  2.ɾ��  3.��	4.��  5.���
							if(y==1) L=insert(L);
							else if(y==2) {
								delecla_menu();
								int y;
								char con1='y';
								string book;
								string start;
								while(con1=='y'){
									cout<<"�������й�ɾ���Ĺ���:";
									cin>>y;
									//1����ţ�2���� 3.��ѧ��
									if(y==1) {cout<<"������Ҫɾ���γ̵ı��:";cin>>num;L=deleByNum(L,num);}
									else if(y==2) {cout<<"������Ҫɾ���Ŀγ���:";cin>>book;L=deleByName(L,book);}
									else if(y==3) break;	
									cout<<endl;
									cout<<"�Ƿ����ɾ����y:����,�����������һ��):";
									cin>>con1;
									cout<<endl;
								}
							}
							else if(y==3) {
								updatecla_menu();
								int y;
								char con2='y';
								while(con2=='y'){
									cout<<"�������й��޸ĵĹ���:";
									cin>>y;
									//1���� 2.��ѧ��
									if(y==1)	L=updateName(L);
									else if(y==2) L=updateStart(L);
									else if(y==3) break;	
									cout<<endl;
									cout<<"�Ƿ�����޸ģ�y:����,�����������һ��):";
									cin>>con2;
									cout<<endl;
								}
							}
							else if(y==4) {
								searchcla_menu();
								char con3='y';
								int y;
								while(con3=='y'){
									cout<<"�������йز�ѯ�Ĺ���:";
									cin>>y;
									//1.���  2.�γ���  3.����ѧ��
									if(y==1) L=search_num(L);
									else if(y==2) L=search_name(L);
									else if(y==3) L=search_start(L);
									else if(y==4) break;
									cout<<endl;
									cout<<"�Ƿ������ѯ��y:����,�����������һ��):";
									cin>>con3;
									cout<<endl;
								}
							}
							else if(y==5) out(L);
							else if(y==6) break;
							cout<<endl;
							cout<<"�Ƿ�����йؿγ̣�y:����,�����������һ��):";
							cin>>con;
							cout<<endl;
							writeFile(L);
						}
						break;
			}
			case 7:{	char con4='y';
						while(con4=='y'){
							s=selectcla(s,L);
							cout<<endl;
							cout<<"�Ƿ����ѡ�Σ�y:����,�����������һ��):";
							cin>>con4;
							cout<<endl;
							writeFile(s);
						}
						break;
					}
			case 8:{	print();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"�������й�����Ĺ���:";
							cin>>y;
							//	1.�༶  2.�Ա�  3.ȫ��
							if(y==1) searchBycla(s);
							else if(y==2) searchBysex(s);
							else if(y==3) searchByselect(s);
							if(y==4) out(s);
							else if(y==5) break;
							cout<<endl;
							cout<<"�Ƿ���������y:����,�����������һ��):";
							cin>>con;
							cout<<endl;
						}
						break;
					}
			default:{
				writeFile(s);
				exit(0);
			}
		}		
	}
}

