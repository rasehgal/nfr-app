// Rashmi Sehgal June 2016
// gfunc.cpp
// implementation of the qattr data structure and
// gfunc header file that allows for easier black 
// box gui functions

using namespace std;
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <sstream>
#include "qattr.h"

// root shared and acceptable to main
qaTree* proj_root = NULL;

//attribute id counters
int csft = 0;
int csec = 0;
int cavb = 0;
int ccmp = 0;
int cftl = 0;
int unsup = 0;

// find_attr
// input: project root, category name, attribute ID
// output: node associated with attribute of choice
qaNode* find_attr(qaTree* proj, string cat, string attr) {
   if (proj == NULL) {
      printf("error: no project found");
      return NULL;
   }
   // check that there is anything to iterate over
   if (proj->cachildren.size()>0) {
      // search for correct category to look through
      for (size_t child = 0; child < proj->cachildren.size(); child++) { 
         if (cat.compare(proj->cachildren[child]->name) == 0) {
             qaTree* categ = proj->cachildren[child];
             // search for correct attribute ID and return node
             for (size_t atch = 0; atch < categ->children.size(); atch++) {
                 if (attr.compare(categ->children[atch]->ID) == 0) {
                    return categ->children[atch];
                 }
             } 
             // if no matching attribute
             return NULL;
         }
      }
      printf("error: no match for inputted category title");
      return NULL;
   }

   printf("error: project is empty");
   return NULL;
}

// find_cat
// input: project root, category name
// output: category "tree" root or null
qaTree* find_cat(qaTree* proj, string cat) {
   qaTree* categ;
   if (proj->cachildren.size()>0) {
      // search for correct category name by iterating through category children
      // of project root
      for (size_t child = 0; child < proj->cachildren.size(); ++ child) {
         if (cat.compare(proj->cachildren[child]->name) == 0) {
             categ = proj->cachildren[child];
             return categ;
         }
      }
   }
   return NULL;
}

// isEmpty
// input: project or category name 
// output: whether it is empty or not
bool isEmpty(qaTree* root) {

   if (root == NULL) {
      printf("error; no such root");
      return false;
   }
   
   // double check that root has no attr or categ children
   if ((root->children.empty()) && (root->cachildren.empty())) {
      return true;
   }

   return false;
}

// create_proj
// input: string name of new project
// output: creates new project tree,
// sets root of this tree to be project root
qaTree* create_proj(string s) {
   proj_root = newTree(s);
   return proj_root;
}

// create_ID
// input: category
// output: ID for attribute being added/"edited"
// helper function
//
// IN PROGRESS; ADD W/O EDIT
string create_ID(string categ){
   std::ostringstream oss;
   string id = categ;
   //check category
   
   //safety
   if (categ.compare("sft") == 0) {
      csft++;
      oss << csft;
   }
   //security
   else if (categ.compare("sec") == 0) {
      csec++;
      oss << csec;
   }
   //availability
   else if (categ.compare("avb") == 0) {
      cavb++;
      oss << cavb;
   }
   //completeness
   else if (categ.compare("cmp") == 0) {
      ccmp++;
      oss << ccmp;
   }
   //failure tolerance
   else if (categ.compare("ftl") == 0) {
      cftl++;
      oss << cftl;
   }
   
   // only works for certain attributes at this time
   else {
      printf("FATAL ERROR: category %s unsupported at this time.\n", categ.c_str());
      exit(1);
   }

   // add new data to id string and return complete
   id+= oss.str();
   return id;
}

// input: project root, category name, attribute info
// output: void; node added to correct branch of tree
// add (distinction between categories must be incorporated)
// adds a new attribute to the category of choice 
string add_attr(qaTree* proj, string cat, string src, string stim, string env,
              string afct, string rsp, string rspm) {
   qaTree* categ = find_cat(proj, cat);
   // create category child if none exists
   if (categ  == NULL) {
      categ = newTree(cat);
      adoptcat(proj, categ);
   } 

   //create new node
   string new_ID = create_ID(cat);
   qaNode* attr = newattr(new_ID, src, stim, env, afct, rsp, rspm);
   // if attribute to be added is a duplicate, print error and exit
   // (later can be edited so that it asks if you want to edit previous one)
   if (find_attr(proj, cat, attr->ID) != NULL) {
      printf("Error; Attribute already exists");
      return NULL;
   }
   // else adopt
   adoptattr(categ, attr);      
   return new_ID;
}

// remove
// removes a specific attribute from project tree
void rem_attr(qaTree* proj, string cat, string attr_ID) {
   qaTree* categ = find_cat(proj, cat);

   // remove attr so that no trace of it exists furthermore
   for (size_t child = 0; child < categ->children.size(); child++) {
      if (categ->children[child]->ID.compare(attr_ID) == 0) { 
         categ->children.erase(categ->children.begin()+child);
      }
   }
   // if this deletion results in an empty category, delete category
   if (categ->children.empty()) {
      for (size_t ctg = 0; ctg < proj->cachildren.size(); ctg++) {
         if (proj->cachildren[ctg]->name.compare(categ->name) == 0) {
            proj->cachildren.erase(proj->cachildren.begin()+ctg);
         } 
      }
   // memory things
   free(categ);

   }
   
}

void rem_cat(qaTree* root, string cat) {
   qaTree* categ = find_cat(root, cat);
   if (categ == NULL) {
      printf("Error; cannot delete. Code: no such category");
      return;
   }
   
   // for vectors size greater than 1, use erase/begin/end funcs
   if(categ->children.size()>1) {
      vector<qaNode*>::iterator it = categ->children.begin();
      if (!categ->children.empty()) {
         while (it != categ->children.end()) { 
            it = categ->children.erase(it);
            it++;
         }
      }
   }

   // can't implement for size <2; base case using regular for loop to delete last element
   if(categ->children.size()==1) {
         for (size_t child = 0; child < categ->children.size(); child++) {
            rem_attr(root, cat, categ->children[child]->ID);
         }
   }
   
}    
     
     
     
void rem_project(qaTree* root) {

   // iterate along all children but the last in case of edge case
   // delete node/tree root iterator is at
   if (!root->cachildren.empty()) {
      vector<qaTree*>::iterator cat = root->cachildren.begin(); 
      while (cat !=  root->cachildren.end()) {
         cat = root->cachildren.erase(cat);
         cat++;
      } 
      
      // delete final node/tree root
      for (size_t branch = 0; branch < root->cachildren.size(); branch++) {
         rem_cat(root, root->cachildren[branch]->name);
      }
   }
 
   // delete root now that the rest of the tree is gone
   if (root->cachildren.empty()) {
      delete root;
      return;
   }
   
}

// recursively called to handle node-node
// parent-child printing
// called by dump_tree to handle node-tree
// parent-child printing
void dump_node(FILE* outfile, qaNode* node) {

   // print this node first
   fprintf(outfile, "\t\t Attribute %s\n", node->ID.c_str());
   fprintf(outfile, "\t\t\t Source: %s\n", node->src.c_str());
   fprintf(outfile, "\t\t\t Stimulus: %s\n", node->stim.c_str());
   fprintf(outfile, "\t\t\t Environment: %s\n", node->env.c_str());
   fprintf(outfile, "\t\t\t Artifact: %s\n", node->afct.c_str());
   fprintf(outfile, "\t\t\t Response: %s\n", node->rsp.c_str());
   fprintf(outfile, "\t\t\t Response Measure: %s\n", node->rspm.c_str());

   // handle node's node children
   for (size_t child = 0; child < node->children.size(); ++child) {
      dump_node(outfile, node->children[child]);
   }
}

// helper function
// recursively called to handle tree-tree
// parent-child printing
// called by dump_proj to handle tree-root
// parent-child printing
void dump_tree(FILE* outfile, qaTree* root) {

   // how to print each "tree" thingy
   if (root == proj_root) {
      fprintf (outfile, "Project: %s\n", root->name.c_str());
   } else {
      fprintf (outfile, "\tCategory: %s\n", root->name.c_str());
   }
   // handle category children first; recursive
   for (size_t child = 0; child < root->cachildren.size(); ++child) {
      dump_tree(outfile, root->cachildren[child]);
   }

   // now handle attribute children (node children of category trees only)
   for (size_t child = 0; child < root->children.size(); ++ child) {
      dump_node(outfile, root->children[child]);
   }
}

// print project specs to a file
// prints the tree out to a file named appropriately
void dump_project(FILE* outfile, qaTree* proj){
   if (proj == NULL) return;
   dump_tree(outfile, proj);
}


