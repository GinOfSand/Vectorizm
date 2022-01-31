#pragma once
template <class T>
class Vectorizm
{
private:
	T param;
	int vcoin = 6;
	T* mass = nullptr;
public:
	
	Vectorizm(T param) :param{ param } {
		mass = new T[vcoin];
		for (int i = 0; i < vcoin; i++) {
			mass[i] = 0;
		}
		mass[0] = param;
	}
	Vectorizm() {
		mass = new T[vcoin];
		for (int i = 0; i < vcoin; i++) {
			mass[i] = 0;
		}
	}
	int getVecsize() {
		return vcoin;
	}
	T getVec_i(int i) {
		return mass[i];
	}
	void set_i_Vec(T name,int i) {
		mass[i] = name;
	}
	void setVect(T param) {
		int nullCoin = 0;
		for (int i = 0; i < vcoin; i++) {
			if (mass[i] == 0)
				nullCoin++;
			if (mass[i] == 0) {
				mass[i] = param;
				if (i >= vcoin / 1.2) {
					groVec();
					break;
				}
				if (nullCoin <= vcoin / 1.5) {
					clearVoid();
					break;
				}
			}
		}
	}
	void groVec() {
		
			T* news = new T[vcoin * 2];
			for (int i = 0; i < (vcoin * 2); i++) {
				news[i] = 0;
			}
			for (int i = 0; i < vcoin; i++) {
				if(mass[i] != 0)
				news[i] = mass[i];
			}
			delete[]mass;
			mass = news;
			vcoin *= 2;
		
	}
	void clearVoid() {
		int selec = 0;
		for (int i = 0; i < vcoin; i++) {
			if (mass[i] == 0) {
				selec++;
			}
		}
		if (selec > vcoin / 1.5) {

			T* news = new T[vcoin / 2];
			for (int i = 0; i < (vcoin / 2); i++) {
				news[i] = 0;
			}
			int c = 0;
			for (int i = 0; i < vcoin; i++) {
				if (mass[i] != 0) {
					news[c] = mass[i];
					c++;
				}

			}
			vcoin /= 2;
			delete[]mass;
			mass = news;
		}
		
	}
	void displayVec() {
		std::cout << " \n";
		for (int i = 0; i < vcoin; i++)
			std::cout << this -> mass[i] << std::endl;
		std::cout << " \n";
	}
};

