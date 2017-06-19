#include<iostream>
#include<string> 
#include<fstream>
#define M 100 
using namespace std;
typedef struct node *pointer; 
struct  node
{  
	string no;		//学号
	string name;	//姓名
	string cla;	    //班级
	string sex;		//性别 
	string phone;	//手机号码
	string sele;	//选修课程
	pointer next;
};
typedef pointer stu; 
/*课程*/
typedef struct  sub 
{ 	 string num;				//课程编号
	 string book;			//课程名
	 string start;				//开课学期
}sub; 
 typedef struct  subject 
 {
	 sub data[M];  
	 int len;
 }subject; 
 /*将文件中的信息写到链表中，课程*/
subject readFile(subject L){
	ifstream cla("class.txt");
	cla.seekg(ios::beg);
	char s[100];
	cla.getline(s,100,'\n');
	while ( cla.getline(s,100,'\n') ){
		L.len++;
		char seg[] = "------"; 
        char charlist[4][50]={""};			/*指定分隔后子字符串存储的位置，这里定义二维字符串数组*/  
        int i =0;  
        char *substr= strtok(s, seg);		/*利用现成的分割函数,substr为分割出来的子字符串*/  
        while (substr != NULL) {    
                strcpy(charlist[i],substr);/*把新分割出来的子字符串substr拷贝到要存储的charlsit中*/  
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
/*将链表写入文件中*/
void writeFile(subject L){
	 ofstream clas("class.txt");
	 int a;
	 clas<<"课程编号------课程名------开课学期"<<endl; 
	 for(a=1;a<=L.len;a++)  {
		 clas<<L.data[a].num<<"------"<<L.data[a].book<<"------"<<L.data[a].start<<endl;
	 }
}
 /*学生信息管理目录*/
 void stu_menu(){
	cout<<"学生信息管理系统"<<endl;
	cout<<"1.添加学生信息"<<endl;
    cout<<"2.删除学生信息"<<endl;
	cout<<"3.修改学生信息"<<endl;
	cout<<"4.查找学生信息"<<endl;
	cout<<"5.学生信息排序"<<endl;
	cout<<"6.课程信息"<<endl;
	cout<<"7.学生选课"<<endl;
	cout<<"8.输出学生信息"<<endl;
	cout<<"9.退出"<<endl;
 }
 int length(stu s) {		//求单链表的长度，即单链表中元素的个数
	int j; 
	pointer p;
	j=0;
	p=s->next;				//从首结点开始
	while(p!=NULL) {		//逐点检测、计数
		j++; 
		p=p->next;
	}		
	return j;
}
 /*按序号查找*/
pointer get(stu head,int i) {	//找第i个数据元素，返回指向该结点的指针0≤i≤n
  int j;
  pointer p;
  if(i==0) return head;
  if(i<0) return NULL;			//位置非法，无此结点
  j=0;							//计数器
  p=head->next;					//从头结点（0号）开始搜索
  while(p!=NULL) {
    j++;
	if(j==i) break;
    p=p->next;					//未到第i点，继续
  }
  return p;						//含找到、未找到两种情况
}
/*写入文件中*/
void writeFile(stu s){
	int len=length(s);
	pointer q;
	ofstream stud("stu.txt");
	int a;
	stud<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
	for(a=1;a<=len;a++)  {
		q=get(s,a);
		stud<<q->no<<"------"<<q->name<<"------"<<q->cla<<"------"<<q->sex<<"------"<<q->phone<<"------"<<q->sele<<endl;
	}
}
/*初始化*/
stu initlist(){
	pointer head;
	head=new node;
	head->next=NULL;
	return head;
}
//读取学生文件
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
		char charlist[50][50]={""};				/*指定分隔后子字符串存储的位置，这里定义二维字符串数组*/  
		int i =0;  
		char *substr= strtok(c, seg);			/*利用现成的分割函数,substr为分割出来的子字符串*/  
		while (substr != NULL) {    
			strcpy(charlist[i],substr);		/*把新分割出来的子字符串substr拷贝到要存储的charlsit中*/  
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
/*查询，根据学生学号，不输出*/
int search_no(stu head,string no) { //定位，找值为x的结点的位置
	int j;
	pointer p;
	j=0;						//计数器
	p=head->next;				//从首结点开始扫描
	while(p!=NULL) {
		j++;
		if(p->no==no) break;		//找到，退出
		p=p->next;					//没找到，继续
	}
	if(p!=NULL) return j;		//找到x
	else return -1;				//没有x，查找失败
}
/*查询，根据学生姓名，不输出*/
int search_name(stu head,string name,int j){	//j计数器
	pointer p;
	p=get(head,j+1);				//从第i-1个节点开始扫描
	while(p!=NULL) {
		j++;
		if(p->name==name) break;		//找到，退出
		p=p->next;						//没找到，继续
		
	}
	if(p!=NULL) return j;		//找到x
	else return -1;				//没有x，查找失败
}
/*查询，根据学生姓名，不输出*/
int search_phone(stu head,string phone,int j){	//j计数器
	pointer p;
	p=get(head,j+1);				//从第i-1个节点开始扫描
	while(p!=NULL) {
		j++;
		if(p->phone==phone) break;		//找到，退出
		p=p->next;						//没找到，继续
		
	}
	if(p!=NULL) return j;		//找到x
	else return -1;				//没有x，查找失败
}
/*查询，根据学生班级，不输出*/
int search_cla(stu head,string cla,int j){	//j计数器
	pointer p;
	p=get(head,j+1);				//从第i个节点开始扫描
	while(p!=NULL) {
		j++;
		if(p->cla==cla) break;		//找到，退出
		p=p->next;						//没找到，继续
	}
	if(p!=NULL) return j;		//找到x
	else return -1;				//没有x，查找失败
}
/*查询，根据学生性别，不输出*/
int search_sex(stu head,string sex,int j){	//j计数器
	pointer p;
	p=get(head,j+1);				//从第i个节点开始扫描
	while(p!=NULL) {
		j++;
		if(p->sex==sex) break;		//找到，退出
		p=p->next;						//没找到，继续
	}
	if(p!=NULL) return j;		//找到x
	else return -1;				//没有x，查找失败
}
/*查询，根据学生选修课，不输出*/
int search_selet(stu head,string selet,int j){	//j计数器
	pointer p;
	p=get(head,j+1);				//从第i个节点开始扫描
	while(p!=NULL) {
		j++;
		if(p->sele==selet) break;		//找到，退出
		p=p->next;						//没找到，继续
	}
	if(p!=NULL) return j;		//找到x
	else return -1;				//没有x，查找失败
}
/*1.添加学生信息：插入到表头*/
void insert(stu head){
	string ch;
	int i;
	pointer s;
	s=new node;
	cout<<"请输入学生学号:";  
	cin>>ch;
	i=search_no(head,ch);
	while(i!=-1)  
    {  
       cout<<"该学号已存在，请输入其他学号：";  
       cin>>ch;  
	   i=search_no(head,ch);
    }  
	s->no=ch;
	cout<<"请输入学生名字:";  
	cin>>ch;
	s->name=ch;
	cout<<"请输入学生班级(如：15级软件1班):";  
	cin>>ch;
	s->cla=ch;
	cout<<"请输入学生性别(填写：男/女):";  
	cin>>ch;
	s->sex=ch;
	cout<<"请输入学生手机号码:";  
	cin>>ch;
	s->phone=ch;
	s->next=head->next;
	head->next=s;
	cout<<"添加成功"<<endl;
}
/*2.删除目录*/
void dele_menu(){
	cout<<"根据***删除学生信息管理"<<endl;
	cout<<"1.学号"<<endl;
    cout<<"2.姓名"<<endl;
	cout<<"3.班级"<<endl;
	cout<<"4.返回"<<endl;
 }
/*根据下标输出*/
void out_one(stu s,int a){
	pointer p;
	p=get(s,a);
	cout<<p->no<<"------"<<p->name<<"------"<<p->cla<<"------"<<p->sex<<"------"<<p->phone<<"------"<<p->sele;
	cout<<endl;
}
/*2.1按学号删除,*/
int deleByNo(stu s,string no){
	  int i=search_no(s,no);
	  pointer p,q;
	  q=get(s,i-1);	//找到第i-1个结点
	  if(q==NULL||q->next==NULL)  {cout<<"不存在该学号的学生!";return 0;}
	  p=q->next;
	  q->next=p->next;
	  delete p;
	  cout<<"删除成功"<<endl;
	  return 1;
}
/*2.2.按学生名删除*/
int deleByName(stu s,string name){
	pointer p,q;
	int i,j=0,n=0;					//j是计数的
	i=search_name(s,name,j);
	//	cout<<i<<endl;
	while(i!=-1){
		out_one(s,i);
		n++;
		j=i;
		i=search_name(s,name,j);
	}
	if(n==0){
		cout<<"不存在该学生";
	}
	else if(n==1){	 
	  q=get(s,j-1);
	  if(q==NULL)  {cout<<"不存在该学生";return 0;}
	  p=q->next;
	  q->next=p->next;
	  delete p;
	  cout<<"删除成功"<<endl;
	}
	else if(n>=2){
		cout<<"有"<<n<<"个同名学生,请根据上方的出现的学生学号到学号删除功能进行删除"<<endl;
	}
	return 0;
}
/*2.3按班级删除*/
int deleByCla(stu s,string cla){
	pointer p,q;
	int i,j=0,n=0;					//j是计数的
	i=search_cla(s,cla,j);
	while(i!=-1){
		 out_one(s,i);
		 q=get(s,i-1);
		 if(q==NULL||q->next==NULL)  {cout<<"删除失败(非法删除位置)!\n";return 0;}
		 p=q->next;
		 q->next=p->next;
		 n++;
		 j=i-1;
		 i=search_cla(s,cla,j);
	}
	if(n==0){
		cout<<"不存在该班级"<<endl;
	}
	else {cout<<"删除成功，一共"<<n<<"名同学"<<endl;}
	return 0;
}
/*3.0改*/
void update_menu(){
	cout<<"修改学生***信息管理"<<endl;
	cout<<"1.姓名"<<endl;
    cout<<"2.班级"<<endl;
	cout<<"3.性别"<<endl;
	cout<<"4.手机号码"<<endl;
	cout<<"5.选修课"<<endl;
	cout<<"6.返回"<<endl;
}
/*3.1修改姓名*/
stu updateName(stu S){
	pointer q;
	string no;
	string name;
	cout<<"请输入要修改的学号:";
	cin>>no;
	int b=search_no(S,no);
	if(b==-1) {cout<<"不存在该学生!"<<endl;}
	else{
		cout<<"请输入要修改的姓名:";
		cin>>name;
		q=get(S,b);
		q->name=name;
		cout<<"修改成功"<<endl;
	}
	return S;
}
/*3.2修改班级*/
stu updateCla(stu S){
	pointer q;
	string no;
	string cla;
	cout<<"请输入要修改的学号:";
	cin>>no;
	int b=search_no(S,no);
	if(b==-1) {cout<<"不存在该学生!"<<endl;}
	else{
		cout<<"请输入要修改的班级:";
		cin>>cla;
		q=get(S,b);
		q->cla=cla;
		cout<<"修改成功"<<endl;
	}
	return S;
}
/*3.3修改性别*/
stu updateSex(stu S){
	pointer q;
	string no;
	string sex;
	cout<<"请输入要修改的学号:";
	cin>>no;
	int b=search_no(S,no);
	if(b==-1) {cout<<"不存在该学生!"<<endl;}
	else{
		cout<<"请输入要修改的性别:";
		cin>>sex;
		q=get(S,b);
		q->sex=sex;
		cout<<"修改成功"<<endl;
	}
	return S;
}
/*3.4修改电话*/
stu updatePhone(stu S){
	pointer q;
	string no;
	string phone;
	cout<<"请输入要修改的学号:";
	cin>>no;
	int b=search_no(S,no);
	if(b==-1) {cout<<"不存在该学生!"<<endl;}
	else{
		cout<<"请输入要修改的电话:";
		cin>>phone;
		q=get(S,b);
		q->phone=phone;
		cout<<"修改成功"<<endl;
	}
	return S;
}
/*6.5输*/
void out(subject L) {
	 int a;   
	 cout<<"课程编号------课程名------开课学期"<<endl; 
	 for(a=1;a<=L.len;a++)  {
		 cout<<L.data[a].num<<"------";
		 cout<<L.data[a].book<<"------";
		 cout<<L.data[a].start<<endl;
	}
 }
/*4.0查询*/
void search_menu(){
	cout<<"根据**信息查询学生"<<endl;
	cout<<"1.学号"<<endl;
	cout<<"2.姓名"<<endl;
	cout<<"3.手机号码"<<endl;
	cout<<"4.返回"<<endl;
}
/*4.1*/
void searchByno(stu S,string no){
	int s=search_no(S,no);
	out_one(S,s);
}
/*4.2根据姓名输出*/
void searchByname(stu s){
	string name;
	cout<<"请输入查询的学生姓名:";
	cin>>name;
	int i,j=0,n=0;					//j是计数的
	i=search_name(s,name,j);
	while(i!=-1){
		out_one(s,i);
		j=i;
		n++;
		i=search_name(s,name,j);
	}
	cout<<"共有"<<n<<"名学生"<<endl;
}
/*4.3根据手机号码查询*/
void searchByphone(stu s){
	string phone;
	cout<<"请输入查询的手机号码:";
	cin>>phone;
	int i,j=0,n=0;					//j是计数的
	i=search_phone(s,phone,j);
	while(i!=-1){
		out_one(s,i);
		j=i;
		i=search_phone(s,phone,j);
	}
	cout<<"共有"<<n<<"名学生"<<endl;
}
/*5.排序*/
void sort(){
	cout<<"根据**信息排序"<<endl;
	cout<<"1.学号"<<endl;
    cout<<"2.班级"<<endl;
	cout<<"3.手机号码"<<endl;
	cout<<"4.返回"<<endl;
}
/*8.4*/
void out(stu head) {
	pointer p;
	int len=length(head);
	if(len>0){
		p=head->next;			//从首结点开始扫描
		cout<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
		while(p!=NULL) {
			cout<<p->no<<"------"<<p->name<<"------"<<p->cla<<"------"<<p->sex<<"------"<<p->phone<<"------"<<p->sele;
			cout<<endl;	
			p=p->next;		  	//p指向下一个结点
		}
		cout<<endl;	
	}
	cout<<"共有"<<len<<"名学生"<<endl;

}
/*5.1根据学号排序:冒泡排序*/
stu Sort_no(stu s){
	int len=length(s);
	//	cout<<len<<endl;
	int flag;
	pointer p,q,l;
	if(len==0) {cout<<"没有学生"<<endl;}
	else if(len==1) {out(s);}
	else if(len>=2){
		for(int i=1;i<=len;i++){	//做n-1趟扫描
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
/*5.2根据班级排序:冒泡排序*/
stu Sort_cla(stu s){
	int len=length(s);
	//	cout<<len<<endl;
	int flag;
	pointer p,q,l;
	if(len==0) {cout<<"没有学生"<<endl;}
	else if(len==1) {out(s);}
	else if(len>=2){
		for(int i=1;i<=len;i++){	//做n-1趟扫描
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
/*5.3根据电话排序:冒泡排序*/
stu Sort_phone(stu s){
	int len=length(s);
	//	cout<<len<<endl;
	int flag;
	pointer p,q,l;
	if(len==0) {cout<<"没有学生"<<endl;}
	else if(len==1) {out(s);}
	else if(len>=2){
		for(int i=1;i<=len;i++){	//做n-1趟扫描
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
/*6.课程信息管理目录*/
  void sub_menu(){
	cout<<"课程信息管理"<<endl;
	cout<<"1.添加课程信息"<<endl;
    cout<<"2.删除课程信息"<<endl;
	cout<<"3.修改课程信息"<<endl;
	cout<<"4.查找课程信息"<<endl;
	cout<<"5.输出课程信息"<<endl;
	cout<<"6.退出"<<endl;
 }
  /*6.4.1查询课程编号*/
 int searchBynum(subject L,string num){
	int i,s=0;
	for(i=1;i<=L.len;i++){
		if(L.data[i].num==num)
		{s=i;break;}
	}
	return s;
 }
 /*6.4.2查询课程名字*/
 int searchByBook(subject L,string book){
	int i,b=0;
	for(i=1;i<=L.len;i++){
		if(L.data[i].book==book)
		{b=i;break;}
	}
	return b;
 }
/*6.1.增加*/
subject insert(subject L){
	L.len++;
	int s=0,b=0;
	int n=L.len;
	cout<<"请输入课程编号:";  
	cin>>L.data[n].num;
	s=searchBynum(L,L.data[n].num);
	while(s!=n)  
    {  
       cout<<"该编号已存在，请输入其他编号：";  
       cin>>L.data[n].num;  
	   s=searchBynum(L,L.data[n].num);
    }  
	cout<<"请输入课程名:";  
	cin>>L.data[n].book;
	b=searchByBook(L,L.data[n].book);
	while(b!=n)  
    {  
       cout<<"该课程名已存在，请输入其他课程名：";  
       cin>>L.data[n].book;  
	   b=searchByBook(L,L.data[n].book);
    }  
	cout<<"请输入开课学期:";  
	cin>>L.data[n].start;
	return L;
}
/*6.2.删除目录*/
void delecla_menu(){
	cout<<"根据***删除课程信息管理"<<endl;
	cout<<"1.课程编号"<<endl;
    cout<<"2.课程名"<<endl;
	cout<<"3.退出"<<endl;
 }
/*6.6.0删除后后部分前*/
subject dele(subject L,int s){
	int j;
	for(j=s+1;j<=L.len;j++){
		L.data[j-1]=L.data[j];
	}
	L.len--;
	cout<<"删除成功;"<<endl;
	return L;
}
/*6.2.1按课程编号删除*/
subject deleByNum(subject L,string i){
	int s;
	if(L.len==0) {cout<<"表空，不能删除"<<endl;}
	else{
		s=searchBynum(L,i);
		cout<<s;
		if(s<1||s>L.len) {cout<<"找不到此课程"<<endl;}
		else{
			L=dele(L,s);
		}
	}
	return L;
}

/*6.2.2按课程名删除*/
subject deleByName(subject L,string book){
	int b=0;
	b=searchByBook(L,book);
	if(b==0){cout<<"不存在此课程!!"<<endl;}
	else{
		L=dele(L,b);
	}
	return L;
}
/*6.3.0改*/
void updatecla_menu(){
	cout<<"修改课程***信息管理"<<endl;
	cout<<"1.课程名"<<endl;
    cout<<"2.开课学期"<<endl;
	cout<<"3.退出"<<endl;
}
/*6.3.1修改课程*/
subject updateName(subject L){
	string num;
	string book;
	cout<<"请输入要修改的编号:";
	cin>>num;
	int n=searchBynum(L,num);
	if(n==0) {cout<<"不存在该课程编号。"<<endl;}
	else{
		cout<<"请输入要修改的课程:";
		cin>>book;
		int b=searchByBook(L,book);
		if(b==0) {L.data[n].book=book;cout<<"修改成功"<<endl;}
		else cout<<"该课程已经存在，编号为"<<L.data[n].num<<endl;
	}
	return L;
}
/*6.3.2 修改开课学期*/
subject updateStart(subject L){
	string num,start;
	cout<<"请输入要修改的编号:";
	cin>>num;
	cout<<"请输入要修改的开课学期:";
	cin>>start;
	int n=searchBynum(L,num);
	L.data[n].start=start;
	cout<<"修改成功"<<endl;
	return L;
}
/*6.4查询*/
void searchcla_menu(){
	cout<<"根据**信息查询课程管理"<<endl;
	cout<<"1.课程编号"<<endl;
	cout<<"2.课程名"<<endl;
    cout<<"3.开课学期"<<endl;
	cout<<"4.退出"<<endl;
}
/*6.4.0 根据编号输*/
void out_one(subject L,int num){
	cout<<"课程编号------课程名------开课学期"<<endl; 
	cout<<L.data[num].num<<"------";
	cout<<L.data[num].book<<"------";
	cout<<L.data[num].start<<endl;
}
/*6.4.1 根据编号查*/
subject search_num(subject L){
	string num;
	int n;
	cout<<"请输入查询的编号:";
	cin>>num;
	n=searchBynum(L,num);
	cout<<n;
	if(n==0) cout<<"不存在该编号;"<<endl; 
	else out_one(L,n);	
	return L;
}
/*6.4.2 根据课程名查*/
subject search_name(subject L){
	string book;
	int b;
	cout<<"请输入查询的课程名:";
	cin>>book;
	b=searchByBook(L,book);
	if(b==0) cout<<"不存在该课程名;"<<endl;
	else out_one(L,b);
	return L;
}
/*6.4.3 根据开课学期查*/
subject search_start(subject L){
	string start;
	cout<<"请输入查询的开课学期:";
	cin>>start;
	int flag=0;
	for(int i=1;i<=L.len;i++){
		if(L.data[i].start==start)
			{out_one(L,i);flag=1;}	
	}
	if(flag==0) cout<<"不存在该学期的课程"<<endl;
	return L;
}
/*7. 学生选课*/
 stu selectcla(stu S,subject L){
	pointer p;
	int n;
    string no,num;
 	cout<<"请输入选课学生学号：";
 	cin>>no;
 	int s=search_no(S,no);
 	if(s==0) cout<<"不存在给学生"<<endl;
 	else{
 		out(L);
	 	cout<<"请输入选课的编号：";
		cin>>num;
		n=searchBynum(L,num);
		if(n==0) cout<<"不存在该课程编号;"<<endl; 
		else {
			p=get(S,s);
			p->sele=num;
			cout<<"选课成功"<<endl;
		}	
	}
 	return S;
 }
/*8.输出*/
void print(){
	cout<<"根据**信息输出"<<endl;
    cout<<"1.班级"<<endl;
	cout<<"2.性别"<<endl;
	cout<<"3.选修课"<<endl;
	cout<<"4.全部"<<endl;
	cout<<"5.返回"<<endl;
}
/*8.1根据班级输出*/
void searchBycla(stu s){
	string cla;
	cout<<"请输入查询的班级:";
	cin>>cla;
	int i,j=0,n=0;					//j是计数的
	i=search_cla(s,cla,j);
	if(n==0&&i!=-1){
		cout<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
	}
	while(i!=-1){
		out_one(s,i);
		j=i;
		n++;
		i=search_cla(s,cla,j);
	}
	cout<<"共有"<<n<<"名学生"<<endl;
}
/*8.2根据性别输出*/
void searchBysex(stu s){
	string sex;
	cout<<"请输入查询的性别:";
	cin>>sex;
	int i,j=0,n=0;					//j是计数的
	i=search_sex(s,sex,j);
	if(n==0&&i!=-1){
		cout<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
	}
	while(i!=-1){
		out_one(s,i);
		j=i;
		n++;
		i=search_sex(s,sex,j);
	}
	cout<<"共有"<<n<<"名学生"<<endl;
}
/*8.3根据选修课输出*/
void searchByselect(stu s){
	string selet;
	cout<<"请输入查询的班级:";
	cin>>selet;
	int i,j=0,n=0;					//j是计数的
	i=search_selet(s,selet,j);
	if(n==0&&i!=-1){
		cout<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
	}
	while(i!=-1){
		out_one(s,i);
		j=i;
		n++;
		i=search_selet(s,selet,j);
	}
	cout<<"共有"<<n<<"名学生"<<endl;
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
		cout<<"请输入要实现的功能：";
		cin>>x;
		switch(x){
			case 1:{  insert(s);cout<<endl;writeFile(s);break;  }
			case 2:{	dele_menu();
						int y;
						char con='y';
						string name;
						string cla;
						while(con=='y'){
							cout<<"请输入有关删除的功能:";
							cin>>y;
							//1：学号，2：名 3.班级  4.选修课
							if(y==1) {cout<<"请输入要删除学生的学号:";cin>>no;j=deleByNo(s,no);}
							else if(y==2) {cout<<"请输入要删除的学生名:";cin>>name;j=deleByName(s,name);}
							else if(y==3) {cout<<"请输入要删除的学生的班级：";cin>>cla;j=deleByCla(s,cla);}
							else if(y==4) break;	
							cout<<endl;
							cout<<"是否继续删除（y:继续,任意任意键返回上一级):";
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
							cout<<"请输入有关修改的功能:";
							cin>>y;
//							//1：名 2.班级 3.性别 4.电话 
							if(y==1)	s=updateName(s);
							else if(y==2) s=updateCla(s);
							else if(y==3) s=updateSex(s);
							else if(y==4) s=updatePhone(s);
							else if(y==5) s=selectcla(s,L);
							else if(y==6) break;	
							cout<<endl;
							cout<<"是否继续修改（y:继续,任意键返回上一级):";
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
							cout<<"请输入有关查询的功能:";
							cin>>y;
							// 1.学号  2.姓名  3.电话号码
							if(y==1) {cout<<"请输入要查询学生的学号:";cin>>no;searchByno(s,no);}
							else if(y==2) searchByname(s);
							else if(y==3) searchByphone(s);
							else if(y==4) break;
							cout<<endl;
							cout<<"是否继续查询（y:继续,任意键返回上一级):";
							cin>>con;
							cout<<endl;
						}
						break;
				   }
			case 5:{	sort();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"请输入有关排序的功能:";
							cin>>y;
							// 1.学号  2.班级  3.电话
							if(y==1) {s=Sort_no(s);out(s);}
							else if(y==2) {s=Sort_cla(s);out(s);}
							else if(y==3) {s=Sort_phone(s);out(s);}
							else if(y==4) break;
							cout<<endl;
							cout<<"是否继续排序输出（y:继续,任意键返回上一级):";
							cin>>con;
							cout<<endl;
						}
						break;
			}
			case 6:{	sub_menu();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"请输入有关课程信息的功能:";
							cin>>y;
							// 1.添加  2.删除  3.改	4.查  5.输出
							if(y==1) L=insert(L);
							else if(y==2) {
								delecla_menu();
								int y;
								char con1='y';
								string book;
								string start;
								while(con1=='y'){
									cout<<"请输入有关删除的功能:";
									cin>>y;
									//1：编号，2：名 3.开学期
									if(y==1) {cout<<"请输入要删除课程的编号:";cin>>num;L=deleByNum(L,num);}
									else if(y==2) {cout<<"请输入要删除的课程名:";cin>>book;L=deleByName(L,book);}
									else if(y==3) break;	
									cout<<endl;
									cout<<"是否继续删除（y:继续,任意键返回上一级):";
									cin>>con1;
									cout<<endl;
								}
							}
							else if(y==3) {
								updatecla_menu();
								int y;
								char con2='y';
								while(con2=='y'){
									cout<<"请输入有关修改的功能:";
									cin>>y;
									//1：名 2.开学期
									if(y==1)	L=updateName(L);
									else if(y==2) L=updateStart(L);
									else if(y==3) break;	
									cout<<endl;
									cout<<"是否继续修改（y:继续,任意键返回上一级):";
									cin>>con2;
									cout<<endl;
								}
							}
							else if(y==4) {
								searchcla_menu();
								char con3='y';
								int y;
								while(con3=='y'){
									cout<<"请输入有关查询的功能:";
									cin>>y;
									//1.编号  2.课程名  3.开课学期
									if(y==1) L=search_num(L);
									else if(y==2) L=search_name(L);
									else if(y==3) L=search_start(L);
									else if(y==4) break;
									cout<<endl;
									cout<<"是否继续查询（y:继续,任意键返回上一级):";
									cin>>con3;
									cout<<endl;
								}
							}
							else if(y==5) out(L);
							else if(y==6) break;
							cout<<endl;
							cout<<"是否继续有关课程（y:继续,任意键返回上一级):";
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
							cout<<"是否继续选课（y:继续,任意键返回上一级):";
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
							cout<<"请输入有关输出的功能:";
							cin>>y;
							//	1.班级  2.性别  3.全部
							if(y==1) searchBycla(s);
							else if(y==2) searchBysex(s);
							else if(y==3) searchByselect(s);
							if(y==4) out(s);
							else if(y==5) break;
							cout<<endl;
							cout<<"是否继续输出（y:继续,任意键返回上一级):";
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

