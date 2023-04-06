//Заданы два неотрицательных целых числа и . Возвращает количество нечетных чисел между и (включительно).lowhighlowhigh


class Solution {
public:
  int (*pt2Func)(int ) = NULL;
    int *low = NULL, *high = NULL;
    int countOdds(int low, int high) 
    {
        string I1 = "Input: ";
        std::cout << I1;
        std::cin >> low >> high;
        
        int l = low, h = high;
        
            if((l > 1) && (l % 2) == 0)
            {
                h -= 1; h -= l;
              
                if((h % 2) > 0)
                {
                    high -= 1; high -= l;
                    return high /= (2 + 1);
                }else
                    high /= 2;
                    return high;
            }
        
t
    }
    pt2Func = &countOdds
    void printExpl()
    {
        int result = this->pt2Func(this->low, this->high);
        std::cout << "Output: " << result;

    }
};
int main()
{
  solution SOL;
  SOL.printExpl();
  
  return 0;
}
