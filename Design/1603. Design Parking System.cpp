class ParkingSystem {
private:
vector<int> carSpace;    
public:
    ParkingSystem(int big, int medium, int small) {
        carSpace=vector<int>(3,0);
        carSpace[0]=big;
        carSpace[1]=medium;
        carSpace[2]=small;
    }
    
    bool addCar(int carType) {
        if(carSpace[carType-1]>0){
            carSpace[carType-1]--;
            return true;
        }
        return false;
    }
};
