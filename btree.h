// btree.h: interface for the btree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BTREE_H__C32A4AB7_0C6A_4E47_8D20_0B36D93C1D33__INCLUDED_)
#define AFX_BTREE_H__C32A4AB7_0C6A_4E47_8D20_0B36D93C1D33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include<iostream>
#include<fstream.h>
#include<string>


class Election{
public:
	char constituency[20],candidate[20],buff[50],party[20];
	int votes;
	int recaddr;
	void insert();
	void read(fstream &fs);
	void del(int addr);
//	void modify();
	void clear();
	
};
class node
{
    public:
    Election a[4];
    node * next[4];
    node * parent;
    int size;
    node();
};

class btree
{
public:
    node * root;
    public:
	    int isDuplicate(Election key);
	    int modifypass(Election key);
		node* findLeaf(Election key,int &level);
		void updateKey(node *p,node *c,Election newKey);
		int search(Election &key);
		void insert(Election key);
		void insertIntoNode(node *n,Election key,node *address);
		void promote(node *n,Election key,node *address);
		node* split(node *n);
		void traverse(node  *ptr);
		btree();
};

#endif // !defined(AFX_BTREE_H__C32A4AB7_0C6A_4E47_8D20_0B36D93C1D33__INCLUDED_)
