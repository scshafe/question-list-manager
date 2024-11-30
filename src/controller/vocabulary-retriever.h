#ifndef VOCABULARY_RETRIEVER_H
#define VOCABULARY_RETRIEVER_H

#include <iostream>

class VocabItem
{
public:
  std::string word;
  std::string definition;
  // std::string example_sentence;
};



class VocabularyRetriever
{
public:
  
  VocabularyRetriever();
  ~VocabularyRetriever();

public:

static VocabularyRetriever *p_inst;

  static VocabularyRetriever* get_instance();
  // {
  //   if (!p_inst)
  //   {
  //     #ifdef USE_SQLITE_FOR_VOCAB_DATABASE
  //       // p_inst = new SqlliteVocabularyRetriever();
  //     #else
  //       JsonVocabularyRetriever* json_ptr = new JsonVocabularyRetriever();
  //       p_inst = json_ptr;
  //     #endif 
  //   }
    
  //   std::cout << "accessing singleton VocabRetriever" << std::endl;
  //   return p_inst;
  // }

  virtual VocabItem get_vocab_item() = 0;

  
};


#endif
