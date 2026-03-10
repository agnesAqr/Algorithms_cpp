    {
        ms.insert(num);
    }
    
    {
    double findMedian()
        bool isEven = ms.size()%2 == 0;
        auto middle = ms.begin();
        if (isEven)
        {
            for (int i=0; i<ms.size()/2-1; ++i) middle++;
            return (*middle + *(++middle))/2.0f;
public:
    MedianFinder(){}
    
    void addNum(int num)
class MedianFinder {
private:
    multiset<int> ms;

        }
        else
        {
            for (int i=0; i<ms.size()/2; ++i) middle++;
            return *middle;
        }
    }
};

