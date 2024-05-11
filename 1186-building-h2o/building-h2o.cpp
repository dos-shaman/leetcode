class H2O {
public:
    int hydrogenCount, oxygenCount;
    mutex m;
    condition_variable cv;
    bool start = false;
    H2O() {
        hydrogenCount = 0;
        oxygenCount = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        /*
        Check if there is a waiting Oxygen atom by oxygenCount == 1
        */
        unique_lock<mutex> lck(m);
        cv.wait(lck, [this](){return oxygenCount == 1;});
        hydrogenCount += 1;
        releaseHydrogen();
        if(hydrogenCount == 2 and oxygenCount == 1)
        {
            hydrogenCount = 0;
            oxygenCount = 0;
            start = false;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        /*
        Check if there are 2 Hydrogen atom avaiable by hydrogenCount == 2
        */
        unique_lock<mutex> lck(m);
        cv.wait(lck, [this](){return start == false || hydrogenCount == 2;});
        start = true;
        oxygenCount += 1;
        releaseOxygen();
        if(hydrogenCount == 2 and oxygenCount == 1)
        {
            hydrogenCount = 0;
            oxygenCount = 0;
        }
        cv.notify_all();
    }
};