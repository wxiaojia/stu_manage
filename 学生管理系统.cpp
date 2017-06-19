#include<iostream>
#include<string> 
#include<fstream>
#define M 100 
#define N 10 
#define NU 20 
using namespace std; 
typedef struct  Student
{  
    string no;  //ѧ��
    string name;//����
    string cla;   //�༶
	string sex;		//�Ա� 
	string phone; //�ֻ�����
	string sele;	//	ѡ�޿γ�
}Student; 
typedef struct stu{
	Student data[M];
	int len;
}stu;
	
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
//��ȡѧ���ļ�
	stu readFile(stu S){
		ifstream stu("stu.txt");
		stu.seekg(ios::beg);
		char s[100];
		stu.getline(s,100,'\n');
		while ( stu.getline(s,100,'\n') ){
			S.len++;
			char seg[] = "------";
			char charlist[50][50]={""};				/*ָ���ָ������ַ����洢��λ�ã����ﶨ���ά�ַ�������*/  
			int i =0;  
			char *substr= strtok(s, seg);			/*�����ֳɵķָ��,substrΪ�ָ���������ַ���*/  
			while (substr != NULL) {    
					strcpy(charlist[i],substr);		/*���·ָ���������ַ���substr������Ҫ�洢��charlsit��*/  
					i++;  
					//	cout<<substr<<endl;
				   substr = strtok(NULL,seg);  
			}   
			S.data[S.len].no=charlist[0];
			 S.data[S.len].name=charlist[1];
			S.data[S.len].cla=charlist[2];
			 S.data[S.len].sex=charlist[3];
			 S.data[S.len].phone=charlist[4];
			S.data[S.len].sele=charlist[5];
			//	cout<<charlist[5]<<endl;
		}
		return S;
	}

	/*������д���ļ���*/
	void writeFile(stu S){
		 ofstream stud("stu.txt");
		 int a;
		 stud<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
		 for(a=1;a<=S.len;a++)  {
			 stud<<S.data[a].no<<"------"<<S.data[a].name<<"------"<<S.data[a].cla<<"------"<<S.data[a].sex<<"------"<<S.data[a].phone<<"------"<<S.data[a].sele<<endl;
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
 /*4.1��ѯѧ��ѧ��*/
int searchByno(stu S,string no){
	int i,s=0;
	for(i=1;i<=S.len;i++){
		if(S.data[i].no==no)
		{s=i;break;}
	}
	return s;
 }
/*1.����*/
stu insert(stu S){
	S.len++;
	int s=0,b=0;
	int n=S.len;
	cout<<"������ѧ��ѧ��:";  
	cin>>S.data[n].no;
	s=searchByno(S,S.data[n].no);
	while(s!=n)  
    {  
       cout<<"��ѧ���Ѵ��ڣ�����������ѧ�ţ�";  
       cin>>S.data[n].no;  
	   s=searchByno(S,S.data[n].no);
    }  
	cout<<"������ѧ������:";  
	cin>>S.data[n].name;
	cout<<"������ѧ���༶(�磺15�����1��):";  
	cin>>S.data[n].cla;
	cout<<"������ѧ���Ա�(��д����/Ů):";  
	cin>>S.data[n].sex;
	cout<<"������ѧ���ֻ�����:";  
	cin>>S.data[n].phone;
	cout<<"��ӳɹ�"<<endl;
	return S;
}
/*2.ɾ��Ŀ¼*/
void dele_menu(){
	cout<<"����***ɾ��ѧ����Ϣ����"<<endl;
	cout<<"1.ѧ��"<<endl;
    cout<<"2.����"<<endl;
	cout<<"3.�༶"<<endl;
	cout<<"4.����"<<endl;
 }
/*2.ɾ����󲿷�ǰ��*/
stu dele(stu S,int s){
	int j;
	for(j=s+1;j<=S.len;j++){
		S.data[j-1]=S.data[j];
	}
	S.len--;
	cout<<"ɾ���ɹ�;"<<endl;
	return S;
}
/*�����±����*/
void out_one(stu S,int a){
	cout<<S.data[a].no<<"------";
	cout<<S.data[a].name<<"------";
	cout<<S.data[a].cla<<"------";
	cout<<S.data[a].sex<<"------";
	cout<<S.data[a].phone<<"------";
	cout<<S.data[a].sele<<endl;
	cout<<endl;
}
/*2.1��ѧ��ɾ��*/
stu deleByNo(stu S,string i){
	int s;
	if(S.len==0) {cout<<"��գ�����ɾ��"<<endl;}
	else{
		s=searchByno(S,i);
		cout<<s;
		if(s<1||s>S.len) {cout<<"�Ҳ�����ѧ��"<<endl;}
		else{
			S=dele(S,s);
		}
	}
	return S;
}
/*2.2.��ѧ����ɾ��*/
stu deleByName(stu S,string name){
	int flag=0;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].name==name)
			{
				if(flag==0)
					cout<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
					out_one(S,i);
				flag++;
			}	
	}
	cout<<endl;
	if(flag==0) cout<<"�����ڸ�ѧ��"<<endl;
	else if(flag==1){
		S=dele(S,i);
	}
	else{
		cout<<"��"<<flag<<"��ͬ����ѧ����������Ϸ����ֵ�ѧ����ѧ��ɾ������ɾ��"<<endl;
	}
	return S;
}
/*2.3���༶ɾ��*/
stu deleByCla(stu S,string cla){
	int flag=0;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].cla==cla)
			{
				S=dele(S,i);
				flag=1;
			}	
	}
	if(flag==0) cout<<"�ð༶������ѧ��"<<endl;
	else S=deleByCla(S,cla);
	return S;
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
	string no;
	string name;
	cout<<"������Ҫ�޸ĵ�ѧ��:";
	cin>>no;
	cout<<"������Ҫ�޸ĵ�����:";
	cin>>name;	
	int b=searchByno(S,no);
	if(b==0) {cout<<"�����ڸ�ѧ��!"<<endl;}
	else{ S.data[b].name=name;cout<<"�޸ĳɹ�"<<endl;}
	return S;
}
/*3.2�޸İ༶*/
stu updateCla(stu S){
	string no;
	string cla;
	cout<<"������Ҫ�޸ĵ�ѧ��:";
	cin>>no;
	cout<<"������Ҫ�޸ĵİ༶:";
	cin>>cla;
	int n=searchByno(S,no);
	if(n==0) {cout<<"�����ڸ�ѧ��!"<<endl;}
	else{ S.data[n].cla=cla;cout<<"�޸ĳɹ�"<<endl;}
	return S;
}
/*3.3�޸��Ա�*/
stu updateSex(stu S){
	string no;
	string sex;
	cout<<"������Ҫ�޸ĵ�ѧ��:";
	cin>>no;
	cout<<"������Ҫ�޸ĵ��Ա�:";
	cin>>sex;
	int n=searchByno(S,no);
	if(n==0) {cout<<"�����ڸ�ѧ��!"<<endl;}
	else{ S.data[n].sex=sex;cout<<"�޸ĳɹ�"<<endl;}
	return S;
}
/*3.4�޸ĵ绰*/
stu updatePhone(stu S){
	string no;
	string phone;
	cout<<"������Ҫ�޸ĵ�ѧ��:";
	cin>>no;
	cout<<"������Ҫ�޸ĵĵ绰����:";
	cin>>phone;
	int n=searchByno(S,no);
	if(n==0) {cout<<"�����ڸ�ѧ��!"<<endl;}
	else{ S.data[n].phone=phone;cout<<"�޸ĳɹ�"<<endl;}
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
/*3.5 �޸�ѡ�޿�*/
stu updateA(stu S,subject L){
	string no;
	string sele;
	cout<<"������Ҫ�޸ĵ�ѧ��:";
	cin>>no;
	cout<<"������Ҫ�޸ĵ�ѡ�޿�:";
	cin>>sele;
	int n=searchByno(S,no);
	// ���ѡ�޿���Ϣ
	out(L);
	if(n==0) {cout<<"�����ڸ�ѧ��!"<<endl;}
	else{ S.data[n].sele=sele;cout<<"�޸ĳɹ�"<<endl;}
	return S;
}
/*4.0��ѯ*/
void search_menu(){
	cout<<"����**��Ϣ��ѯѧ��"<<endl;
	cout<<"1.ѧ��"<<endl;
	cout<<"2.����"<<endl;
	cout<<"3.�ֻ�����"<<endl;
	cout<<"4.����"<<endl;
}
/*4.1����ѧ�����*/
void search_no(stu S){
	string no;
	cout<<"������Ҫ��ѯ��ѧ��:";
	cin>>no;
	int s=searchByno(S,no);
	if(s==0){
		cout<<"�����ڸ�ѧ��"<<endl;
	}
	else{
		cout<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
		out_one(S,s);
	}
}
/*4.2�����������*/
void search_name(stu S){
	string name;
	cout<<"�������ѯ��ѧ����:";
	cin>>name;
	int flag=0;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].name==name)
			{
				if(flag==0)
					cout<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
					out_one(S,i);
				flag++;
			}	
	}
	if(flag==0) cout<<"�����ڸ�ѧ��"<<endl;
}
/*4.3�����ֻ������ѯ*/
void search_phone(stu S){
	string phone;
	cout<<"�������ѯ���ֻ�����:";
	cin>>phone;
	int flag=0;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].phone==phone)
			{
				if(flag==0)
					cout<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
					out_one(S,i);
				flag++;
			}	
	}
	if(flag==0) cout<<"�����ڸ��ֻ���"<<endl;
}
/*5.����*/
void sort(){
	cout<<"����**��Ϣ����"<<endl;
	cout<<"1.ѧ��"<<endl;
    cout<<"2.�༶"<<endl;
	cout<<"3.�ֻ�����"<<endl;
	cout<<"4.����"<<endl;
}
/*5.1����ѧ������:ð������*/
stu Sort_no(stu S){
	int flag,n=S.len;
	for(int i=1;i<=n;i++){	//��n-1��ɨ��
		flag=0;
		for(int j=n;j>=i+1;j--){
			if(S.data[j].no<S.data[j-1].no){
				flag=1;
				S.data[0]=S.data[j];
				S.data[j]=S.data[j-1];
				S.data[j-1]=S.data[0];
			}
		}
	if(!flag) break;
	}
	return S;
}
/*5.2���ݰ༶����:ð������*/
stu Sort_cla(stu S){
	int flag,n=S.len;
	for(int i=1;i<=n;i++){	//��n-1��ɨ��
		flag=0;
		for(int j=n;j>=i+1;j--){
			if(S.data[j].cla<S.data[j-1].cla){
				flag=1;
				S.data[0]=S.data[j];
				S.data[j]=S.data[j-1];
				S.data[j-1]=S.data[0];
			}
		}
	if(!flag) break;
	}
	return S;
}
/*5.3���ݵ绰����:ð������*/
stu Sort_phone(stu S){
	int flag,n=S.len;
	for(int i=1;i<=n;i++){	//��n-1��ɨ��
		flag=0;
		for(int j=n;j>=i+1;j--){
			if(S.data[j].phone<S.data[j-1].phone){
				flag=1;
				S.data[0]=S.data[j];
				S.data[j]=S.data[j-1];
				S.data[j-1]=S.data[0];
			}
		}
	if(!flag) break;
	}
	return S;
}
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
 	string no;
 	cout<<"������ѡ��ѧ��ѧ�ţ�";
 	cin>>no;
 	int s=searchByno(S,no);
 	if(s==0) cout<<"�����ڸ�ѧ��"<<endl;
 	else{
 		out(L);
	 	cout<<"������ѡ�εı�ţ�";
	 	cin>>S.data[s].sele;
	 	cout<<"ѡ�γɹ�"<<endl;
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
void search_cla(stu S){
	string cla;
	cout<<"�������ѯ�İ༶:";
	cin>>cla;
	int flag=0;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].cla==cla)
			{
				if(flag==0)
					cout<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
					out_one(S,i);
					flag++;
			}	
	}
	if(flag==0) cout<<"�����ڸð༶"<<endl;
	else cout<<"�ð���"<<flag<<"��ѧ��"<<endl;
}
/*8.2�����Ա����*/
void search_sex(stu S){
	string sex;
	cout<<"�������ѯ���Ա�:";
	cin>>sex;
	int flag=0;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].sex==sex)
			{
				if(flag==0)
					cout<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
					out_one(S,i);
					flag++;
			}	
	}
	if(flag==0) cout<<"�����ڸ��Ա��ѧ��"<<endl;
	else cout<<"����"<<flag<<"������Ҫ���ѧ��"<<endl;
}
/*8.3 ���ѡ�޿�*/
void search_select(stu S){
	string num;
	int flag=0;
	cout<<"�������ѯ�Ŀγ̱�ţ�";
	cin>>num;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].sele==num){
			if(flag==0)
				cout<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
				out_one(S,i);
				flag++;
		}
	}
	if(flag==0) cout<<"û��ѧ��ѡ���ſγ�";
	else cout<<"����"<<flag<<"��ѧ��ѡ�����ſγ�"<<endl;
}
/*8.4���ȫ��*/
void out(stu S) {
	 int a;   
	 cout<<"ѧ��------����------�༶------�Ա�------�ֻ�����------ѡ�޿�"<<endl; 
	 for(a=1;a<=S.len;a++)  {
		 cout<<S.data[a].no<<"------";
		 cout<<S.data[a].name<<"------";
		 cout<<S.data[a].cla<<"------";
		cout<<S.data[a].sex<<"------";
		cout<<S.data[a].phone<<"------";
		cout<<S.data[a].sele<<endl;
	}
	cout<<"����"<<S.len<<"��ѧ��"<<endl;
 }
void main(){
   	stu S;  
	string num;
	int x;
	string no;
	S.len=0;
	S=readFile(S);
	subject L;  
	L.len=0;
	L=readFile(L);
	while(1){
		stu_menu();
		cout<<endl;
		cout<<"������Ҫʵ�ֵĹ��ܣ�";
		cin>>x;
		switch(x){
			case 1:{  S=insert(S);cout<<endl;break;  }
			case 2:{	dele_menu();
						int y;
						char con='y';
						string name;
						string cla;
						while(con=='y'){
							cout<<"�������й�ɾ���Ĺ���:";
							cin>>y;
							//1��ѧ�ţ�2���� 3.�༶  4.ѡ�޿�
							if(y==1) {cout<<"������Ҫɾ��ѧ����ѧ��:";cin>>no;S=deleByNo(S,no);}
							else if(y==2) {cout<<"������Ҫɾ����ѧ����:";cin>>name;S=deleByName(S,name);}
							else if(y==3) {cout<<"������Ҫɾ����ѧ���İ༶��";cin>>cla;S=deleByCla(S,cla);}
								// else if(y==4) dele_select(S);
							else if(y==4) break;	
							cout<<endl;
							cout<<"�Ƿ����ɾ����y:����,���������������һ��):";
							cin>>con;
							cout<<endl;
						}
						break;
					}
			case 3:{	update_menu();
						int y;
						char con='y';
						while(con=='y'){
							cout<<"�������й��޸ĵĹ���:";
							cin>>y;
							//1���� 2.�༶ 3.�Ա� 4.�绰 
							if(y==1)	S=updateName(S);
							else if(y==2) S=updateCla(S);
							else if(y==3) S=updateSex(S);
							else if(y==4) S=updatePhone(S);
							else if(y==5) S=updateA(S,L);
							else if(y==6) break;	
							cout<<endl;
							cout<<"�Ƿ�����޸ģ�y:����,�����������һ��):";
							cin>>con;
							cout<<endl;
						}
						break;
					}
			case 4:{	search_menu();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"�������йز�ѯ�Ĺ���:";
							cin>>y;
							// 1.ѧ��  2.����  3.�绰����
							if(y==1) search_no(S);
							else if(y==2) search_name(S);
							else if(y==3) search_phone(S);
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
							if(y==1) {S=Sort_no(S);out(S);}
							else if(y==2) {S=Sort_cla(S);out(S);}
							else if(y==3) {S=Sort_phone(S);out(S);}
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
							S=selectcla(S,L);
							cout<<endl;
							cout<<"�Ƿ����ѡ�Σ�y:����,�����������һ��):";
							cin>>con4;
							cout<<endl;
							writeFile(L);
						}
						break;
					}
			case 8:{	print();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"�������й�����Ĺ���:";
							cin>>y;
							// 1.�༶  2.�Ա�  3.ȫ��
							if(y==1) search_cla(S);
							else if(y==2) search_sex(S);
							else if(y==3) search_select(S);
							else if(y==4) out(S);
							else if(y==5) break;
							cout<<endl;
							cout<<"�Ƿ���������y:����,�����������һ��):";
							cin>>con;
							cout<<endl;
						}
						break;
					}
			default:{writeFile(S);exit(0);}
		}		
	}
}


// �������ѧ���ǼǱ��е����湦�ܡ�
// �ǼǱ��а�����ѧ�š��������༶���磺15�����1�ࣩ���Ա��ֻ����롢ѡ�޿γ̵���Ϣ��
// �����������������ݽṹʵ�֣�
// ��1�����룺��ĳѧ���Ļ�����Ϣ���뵽�ǼǱ��У�
 	// ��ѧ�Ų����ظ������ʱҪ��ѯ��ѧ���Ƿ����,�ظ�ʱ��������		ok
// ��2��ɾ���������������Ļ�����Ϣɾ����
	// �ٸ���ѧ��ɾ��												ok
	// �ڸ�������ɾ�� �����ģ��������ѧ����Ϣ						ok
	// �۸��ݰ༶ɾ��												ok
// ��3���޸ģ��Ի�����Ϣ������������޸ģ�
	// ���޸�����													ok
	// ���޸İ༶													ok
	// ���޸��Ա�													ok
	// ���޸��ֻ�����												ok
	// �޸�ѡ�޿γ�													?
// ��4����ѯ����������������ѧ�Ż��������ֶΣ���ѧ����
	// ��ѧ�Ų�ѯ													ok
	// ��������ѯ													ok
	// ���ֻ������ѯ												ok
	// ѡ�޿ε�ѧ����ѯ												?
// ��5�����򣺸���ѧ����Ϣ�����磺ѧ�Ż�绰����ȣ��������򣬾�������߲��Һ�ά�����ܣ�
	// ��ѧ������													ok
	// �ڰ༶����													ok
	// �۵绰��������												ok
// ��6�����ӿγ���Ϣ���磺�γ������γ̱�š�����ѧ�ڵ���Ϣ���������ӡ�ɾ���Ͳ��Һ���������޴洢�ṹ����
	// �γ���Ϣ														ok
// ��7��ʵ��ѧ����ѡ�ι��ܣ�ѧ��ѡ��һ�ſκ󣬸ÿγ���Ϣ������ڸ�����ѡ�޿γ̡�����
		// ѡ�ޣ�����ѧ��ѧ�ţ�����γ���Ϣ��ѧ��ѡ�Σ�				ok
// ��8����������ǼǱ��е�����ѧ���ģ���������������Ϣȫ�������Ҫ���ʽ����������鿴��
	// �۰༶��ѯ													ok
	// ���Ա��ѯ													ok
	//��ȫ��ѧ��														ok

// ��չ����Ҫ��
// ��1�����룺���û���Ϣ���ļ��������
// ��2�����������û���Ϣ�������ļ��б��棻

