// btree.cpp: implementation of the btree class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "pass.h"
#include "btree.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


node :: node()
{
      for(int i = 0; i < 4; i++)
	  next[i] = NULL;
      parent = NULL;
      size = 0;
}


void btree :: traverse(node *ptr)
{
      if(ptr == NULL)
	return;
      for(int i = 0; i < ptr->size; i++)
	    //cout<<ptr->a[i]<<"    ";
      //cout<<endl;
      for(i = 0;  i < ptr->size;i++)
	  traverse(ptr->next[i]);
    
}

btree :: btree()
{
    root = NULL;
}

node* btree :: findLeaf(Election key,int &level)
{
    node *ptr = root;
    node *prevptr = NULL;
    level = 0;
    int i;
    while(ptr)
    {
	 i = 0;
	  level++;
	  //cout<<level<<endl;
	 while(i < ptr -> size-1 && strcmp(key.candidate , ptr -> a[i].candidate)>0)
		i++;
	  prevptr = ptr;
	 ptr = ptr -> next[i];
    }
    return prevptr;
}

node* btree :: split(node *n)
{
    int midpoint = (n -> size+1)/2;
    int newsize = n->size - midpoint;
    node *newptr = new node;
    node *child;
    newptr->parent = n -> parent;
    int i;
    for(i = 0; i < midpoint; i++)
    {
	newptr->a[i] = n->a[i];
	newptr ->next[i] = n->next[i];
	n->a[i] = n->a[i+midpoint];
	n->next[i] = n->next[i+midpoint];
    }
    n->size = midpoint;
    newptr -> size = newsize;
    for( i = 0; i < n->size; i++)
    {
	child = n->next[i];
	if(child!= NULL)
	child -> parent = n;
    }
    for( i  = 0; i < newptr -> size; i++)
    {
	child = newptr -> next[i];
	if(child!= NULL)
	child -> parent = newptr;
    }
    return newptr;
}

void btree :: updateKey(node *parent,node *child,Election newkey)
{
     if(parent == NULL)
	return;
      if(parent->size == 0)
	    return;
      Election oldkey = child->a[child->size-2];
	  while(parent)
	  {
      for(int i = 0; i < parent->size;i++)
	  if(strcmp(parent->a[i].candidate , oldkey.candidate)==0)
	  { 
		 parent->a[i] = newkey;
	     parent->next[i] = child;
	  }
	  child=parent;
	  parent=parent->parent;
	  }
	  
}
void btree :: insertIntoNode(node *n,Election key,node *address)
{
    int i;
    if( n == NULL)
	return;
    
    for(i = 0; i < n->size; i++)
	if(strcmp(n->a[i].candidate , key.candidate)==0)
	    return;

    i = n->size-1;
    while(i >= 0 && strcmp(n -> a[i].candidate , key.candidate)>0)
    {
		n->a[i+1] = n->a[i];
		n->next[i+1] = n->next[i];
		i--;
    }
    i++;
    n->a[i] = key;
    n->next[i] = address;
    n->size++;
    if( i == n->size-1)
	updateKey(n->parent,n,key);
}

void btree :: promote(node *n,Election key,node *address)
{
    if( n == NULL)
	return;

    if(n -> size < 4)
    {
	insertIntoNode(n,key,address);
	return;
    }

    if( n == root)
    {
	root = new node;
	
	n->parent = root;
    }
    node *newptr = split(n);
    node *t;
    if(strcmp(key.candidate , n->a[0].candidate)<0)
	  t = newptr;
    else
	  t = n;
    insertIntoNode(t,key,address);
    promote(n->parent,n->a[n->size-1],n);
    promote(newptr->parent,newptr->a[newptr->size-1],newptr);
    
}

void btree :: insert(Election key)
{
    if( root == NULL)
    {
	  root = new node;
	  root->a[root->size] = key;
	  root->size++;
	  return;
    }
    int level;
    node *leaf = findLeaf(key,level);
    int i;
    for(i = 0; i < leaf->size; i++)
	if(strcmp(leaf -> a[i].candidate , key.candidate)==0)
	{
		//cout<<"The Key to be inserted already exists"<<endl;
		return;
	}
    promote(leaf,key,NULL);
     //cout<<"---------------\n";
     // traverse(root);
      //cout<<"----------------\n";
}
    
int btree :: search(Election &key)
{
       if(root == NULL)
      {	  
		   //cout<<"The tree Does not exist"<<endl;
		   return 0;
      }
      int level;
      node *leaf = findLeaf(key,level);
      int flag = 0;
      for(int i = 0; i < leaf ->size; i++)
	  if(strcmp(leaf->a[i].candidate , key.candidate)==0 )
	  {
		  key=leaf->a[i];
		  return 1;
	      //cout<<"The Key "<<key<<" Exists in the B-Tree at the level"<<level<<endl;
	  }
	  return 0;
      //if(!flag)
	  //cout<<"The Key Searched for was not found"<<endl;
}
void Election::insert()
{
	
	fstream f1("election.txt",ios::app|ios::out);
	//cout<<"enter company and product";
	//cin>>company>>product;
	f1<<candidate<<"|"<<party<<"|"<<constituency<<"|"<<votes<<"\n";
	f1.close();
}

void Election::clear()
{
	for(int i=0;i<50;i++)
		buff[i]='\0';
}

void Election::read(fstream &fs)
{
	char vote[10];
	recaddr = fs.tellg();
	fs.getline(candidate,20,'|');
	fs.getline(party,20,'|');
	fs.getline(constituency,20,'|');
	fs.getline(vote,10,'\n');
	votes=atoi(vote);
}

void Election::del(int addr)
{
	//cout<<"enter company and product";
	//cin>>company>>product;
	fstream fs("election.txt",ios::in|ios::out);
	/*strcpy(buff,constituency);
	strcat(buff,"|");
	strcat(buff,party);
	strcat(buff,"|");
	strcat(buff,candidate);
	strcat(buff,"|");
	strcat(buff,votes);
	strcat(buff,"\n");*/
	//file<<buff;
	fs.seekp(addr);
	fs.write("$",1);
	fs.close();
}

/*int main()
{
    btree b; 
    int choice = 1,key;
    while(choice !=3)
    {
	    //cout<<"1.Insert a Key\n";
	    //cout<<"2.Search a key\n";
	    //cout<<"3.Exit\n";
	    //cin>>choice;
	    switch(choice)

		{
		  case 1: //cout<<"Enter The Key to be inserted in B-Tree\n";
			  //cin>>key;
			  b.insert(key);
			  break;
		  case 2: //cout<<"Enter The key to be searched\n";
			  //cin>>key;
			  b.search(key);
			  break;
	    }
    }
    return 0;
}
*/

  
int btree::modifypass(Election key)
{
	 if(root == NULL)
      {	  
		   return 0;
      }
      int level;
      node *leaf = findLeaf(key,level);
      //int flag = 0;
      for(int i = 0; i < leaf ->size; i++)
	  if(strcmp(leaf->a[i].candidate,key.candidate)==0 && strcmp(leaf->a[i].party,key.party)==0)
	  {
		  
		  fstream f1("election.txt", ios::in | ios::out);
		  char buff[50];
		  //leaf->a[i].recaddr;
		  strcpy(buff,leaf->a[i].candidate);
		  strcat(buff,"|");
		  strcat(buff,leaf->a[i].party);
		  strcat(buff,"|");
		  strcat(buff,key.candidate);
		  strcat(buff,"\n");
		  f1.seekp(leaf->a[i].recaddr);
		  f1.write(buff,strlen(buff));
		  //f1>>buff;
	      //flag = 1;
		  return 1;
	  }
	  return 0;
}

int btree::isDuplicate(Election key)
{
  if(root == NULL)
      {	  
		   //cout<<"The tree Does not exist"<<endl;
		   return 0;
      }
      int level;
      node *leaf = findLeaf(key,level);
      int flag = 0;
      for(int i = 0; i < leaf ->size; i++)
	  if(strcmp(leaf->a[i].candidate , key.candidate)==0)
	  {
		  return 1;
	      //cout<<"The Key "<<key<<" Exists in the B-Tree at the level"<<level<<endl;
	  }
	  return 0;
      //if(!flag)
	  //cout<<"The Key Searched for was not found"<<endl;
}
