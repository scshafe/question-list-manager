
#include <exception>
#include "vocabulary-manager.h"

#include "vocabulary-retriever.h"
#include "vocab-item.h"

#include "sentence-fetcher.h"
#include "my-json-helper.h"
#include "color-printer.h"


VocabularyManager* VocabularyManager::p_inst = nullptr;

VocabularyManager::VocabularyManager()
{
  VocabularyRetriever* vr = VocabularyRetriever::get_instance();
}

VocabularyManager::~VocabularyManager()
{

}

VocabularyManager* VocabularyManager::get_instance()
{
  if (!p_inst)
  {
    p_inst = new VocabularyManager();
  }
  return p_inst;
}

VocabItem VocabularyManager::get_next_vocab_item()
{
  VocabularyRetriever* vr = VocabularyRetriever::get_instance();

  VocabItem vocab_item = vr->get_vocab_item();

  // VocabularyRetriever* vr = VocabularyManager::get_instance();
  try
  {
    SentenceFetcher* sf = SentenceFetcher::get_instance();
    vocab_item.example_sentence = sf->get_sentence(vocab_item.word);
  } catch (std::exception& e)
  {
    CP::print_error(e.what());
  }
  return vocab_item;

}

