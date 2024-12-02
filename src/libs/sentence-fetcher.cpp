
#include <string>

#include "sentence-fetcher.h"
#include "groq-sentence-fetcher.h"

SentenceFetcher* SentenceFetcher::p_inst = nullptr;


SentenceFetcher::SentenceFetcher()
{

}

SentenceFetcher::~SentenceFetcher()
{
  
}

SentenceFetcher* SentenceFetcher::get_instance()
{
  if (!p_inst)
  {
    p_inst = new GroqSentenceFetcher();
  }
  return p_inst;
}

