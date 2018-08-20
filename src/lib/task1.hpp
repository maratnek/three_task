// 1. Дана последовательность целых чисел по модулю не больше 10000.
// Написать функцию нахождения максимального произведения 3-х чисел.
// Вернуть максимальное произведение. Сложность алгоритма линейная O(n).
#pragma once

long long MaxMultThreeNumbers(const int wholeNumList[], size_t count)
{
  if (count < 3)
    throw "Function MaxMultThreeNumbers count must >= 3 is mistaken.";
  else if (count == 3)
    return wholeNumList[0]*wholeNumList[1]*wholeNumList[2];

  const int m_size = 10001;
  int minus[m_size] = {0};
  int plus[m_size] = {0};

  bool zero = false;
  bool positive = false;
  for (size_t i = 0; i < count; ++i) {
    if (wholeNumList[i] < 0 && wholeNumList[i] > -m_size)
      ++minus[ (-wholeNumList[i]) ];
    else if (wholeNumList[i] > 0 && wholeNumList[i] < m_size)
    {
      ++plus[wholeNumList[i]];
      if (!positive)
        positive = true;
    }
    else if (wholeNumList[i] == 0)
      zero = true;
  }
  // Calculate max multiple
  long long max = 0;
  // Not positive numbers
  if (!positive)
  {
    if (zero)
      max = 0;
    else
    {
      max = 1;
      size_t count = 0;
      int i = 0;
      while (count < 3 && i < m_size)
      {
        if (minus[i]--)
        {
          max *= -i;
          ++count;
        }
        else
          ++i;
      }
    }
  }
  // Exist positive
  else
  {
    int multM = 1;
    size_t count = 0;
    int i = m_size - 1;
    while (count < 2 && i > 0)
    {
      if (minus[i]--)
      {
        multM *= i;
        ++count;
      }
      else
        --i;
    }
    int multP = 1;
    count = 0;
    i = m_size - 1;
    while (count < 3 && i > 0)
    {
      if (plus[i]--)
      {
        if (count == 0)
          max = i;
        else
          multP *= i;
        ++count;
      }
      else
        --i;
    }
    max =  max * (multM > multP ? multM : multP);
  }
  return max;
}
