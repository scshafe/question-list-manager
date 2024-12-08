#include <iostream>
#include <string>

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


VocabularyRetriever* VocabularyRetriever::get_instance(std::string filename /*= "/home/debian/vocabulary-words.json"*/)
{
  if (!p_inst)
  {
    #ifdef USE_SQLITE_FOR_VOCAB_DATABASE
      // p_inst = new SqlliteVocabularyRetriever();
    #else
      JsonVocabularyRetriever* json_ptr = new JsonVocabularyRetriever(filename);
      p_inst = json_ptr;
    #endif 
  }
  
  std::cout << "accessing singleton VocabRetriever" << std::endl;
  return p_inst;
}
