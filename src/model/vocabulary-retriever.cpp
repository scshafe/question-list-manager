#include <string>

#include "vocabulary-retriever.h"
#include "json-vocabulary-retriever.h"
#include "color-printer.h"



VocabularyRetriever* VocabularyRetriever::p_inst = nullptr;
std::string VocabularyRetriever::database_file = "/home/debian/vocabulary-words.json";

VocabularyRetriever::VocabularyRetriever()
{
  CP::print_info("VocabularyRetriever constructor");
}

VocabularyRetriever::~VocabularyRetriever()
{

}

void VocabularyRetriever::set_database_file(std::string database_file_override)
{
  database_file = database_file_override;
}


VocabularyRetriever* VocabularyRetriever::get_instance()
{
  if (!p_inst)
  {
    #ifdef USE_SQLITE_FOR_VOCAB_DATABASE
      // p_inst = new SqlliteVocabularyRetriever();
    #else
      JsonVocabularyRetriever* json_ptr = new JsonVocabularyRetriever(database_file);
      p_inst = json_ptr;
    #endif 
  }
  
  CP::print_info("accessing singleton VocabularyRetriever");
  return p_inst;
}
