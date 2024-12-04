

#include "vocabulary-manager.h"
#include "../model/vocabulary-retriever.h"
#include "../model/vocab-item.h"
#include "../libs/sentence-fetcher.h"

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
  SentenceFetcher* sf = SentenceFetcher::get_instance();
  vocab_item.example_sentence = sf->get_sentence(vocab_item.word);

  return vocab_item;

}

