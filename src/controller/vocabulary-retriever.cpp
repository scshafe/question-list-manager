#include <iostream>

#include "vocabulary-retriever.h"
#include "json-vocabulary-retriever.h"

VocabularyRetriever* VocabularyRetriever::p_inst = nullptr;

VocabularyRetriever::VocabularyRetriever()
{
  std::cout << "VocabularyRetriever constructor" << std::endl;

}

VocabularyRetriever::~VocabularyRetriever()
{

}


VocabularyRetriever* VocabularyRetriever::get_instance()
{
  if (!p_inst)
  {
    #ifdef USE_SQLITE_FOR_VOCAB_DATABASE
      // p_inst = new SqlliteVocabularyRetriever();
    #else
      JsonVocabularyRetriever* json_ptr = new JsonVocabularyRetriever();
      p_inst = json_ptr;
    #endif 
  }
  
  std::cout << "accessing singleton VocabRetriever" << std::endl;
  return p_inst;
}

// VocabularyRetriever* VocabularyRetriever::getInstance()
// {
//   static VocabularyRetriever instance;

//   std::cout << "accessing singleton VocabRetriever" << std::endl;

//   return &instance;
// }

