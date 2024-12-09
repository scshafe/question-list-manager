#ifndef VOCABULARY_RETRIEVER_H
#define VOCABULARY_RETRIEVER_H

#include <iostream>

#include "vocab-item.h"

/*

----------This is an INTERFACE class

*/

class VocabularyRetriever
{
public:
  
  VocabularyRetriever();
  ~VocabularyRetriever();

public:

static VocabularyRetriever *p_inst;
static std::string database_file;

  static void set_database_file(std::string database_file);
  static VocabularyRetriever* get_instance();


  virtual VocabItem get_vocab_item() = 0;

  
};


#endif
