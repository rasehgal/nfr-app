// Rashmi Sehgal June 2016
// gfunc.h
// gfunc header file 
// outlines black box gui functions
#ifndef GFUNC_H
#define GFUNC_H

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include "qattr.h"

// returnable project root
extern qaTree* proj_root;

// find_attr
// input: project root, category name, attribute ID
// output: node associated with attribute of choice
qaNode* find_attr(qaTree* proj, string cat, string attr);

// isEmpty
// input: project or category name 
// output: whether it is empty or not
bool isEmpty(qaTree* root);

// create_proj
// input: string representing project title
// output: returns now usable project root
qaTree* create_proj(string s);

// add (distinction between categories must be incorporated)
// adds a new attribute to the category of choice 
// input: project root, category name, attribute info
// output: void; node added to correct branch of tree
// edit: output string to attain ID post-addition
string add_attr(qaTree* proj, string cat, string src, string stim, string env,
              string afct, string rsp, string rspm);

// rem_attr
// input: project root, string representing desired
// category, string representing ID of desired attribute
// output: void; removes designated attribute from the project tree
void rem_attr(qaTree* proj, string categ, string attr_ID);

//rem_cat
//input: project root, string representing desired category
//output: void; removes specified category from the project tree
void rem_cat(qaTree* proj, string categ);

// dump_project
// input: desired file, project root
// output: file containing full printed project details 
// file created according to designated specifications from 
// FILE*
void dump_project(FILE* outfile, qaTree* proj);


// rem_project
// input: project root
// output: void; removes all attributes, categories from
// project tree. sets project root to null. 
void rem_project(qaTree* root);

#endif //gfunc.h
