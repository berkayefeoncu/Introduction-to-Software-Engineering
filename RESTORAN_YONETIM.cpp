#include <iostream>
	#include <string>
	#include <vector>
	#include <algorithm>
	
	using namespace std;
	
	class RestoranYonetimSistemi {
	private:
	    string restoranIsmi;
	    int toplamMasalar;
	    int kullanilabilirMasalar;
	    vector<string> yemekMenusu;
	    vector<int> yemekStoku;
	    vector<double> yemekUcretleri; 
	    vector<string> icecekMenusu;
	    vector<int> icecekStoku;
	    vector<double> icecekUcretleri; 
	    vector<bool> masaMevcutlugu;
	    static int toplamSiparisler;
	
	public:
	    RestoranYonetimSistemi(string isim = "Varsayylan Restoran Ysmi", int masalar = 10, const vector<string>& yemekler = {}, const vector<int>& yemekStok = {}, 
	                                const vector<double>& yemekUcret = {}, const vector<string>& icecekler = {}, const vector<int>& icecekStok = {}, 
	                                const vector<double>& icecekUcret = {})
	        : restoranIsmi(isim), toplamMasalar(masalar), kullanilabilirMasalar(masalar), yemekMenusu(yemekler), yemekStoku(yemekStok), yemekUcretleri(yemekUcret), 
	          icecekMenusu(icecekler), icecekStoku(icecekStok), icecekUcretleri(icecekUcret) {
	            masaMevcutlugu.resize(masalar, true);
	        }
	
	    ~RestoranYonetimSistemi() {
	    	 cout << "Restoran yönetim sistemi örne?i yok edildi." << endl;
	    }
	
	    string getRestoranIsmi() const {
	        return restoranIsmi;
	    }
	    
	    void setRestoranIsmi(const string& name) {
	        restoranIsmi = name;
	    }
	
	    int getToplamMasalar() const {
	        return toplamMasalar;
	    }
	    
	    void setToplamMasalar(int totalTables) {
	        toplamMasalar = totalTables;
	    }
	
	    int getKullanilabilirMasalar() const {
	        return kullanilabilirMasalar;
	    }
	    
	    void setKullanilabilirMasalar(int totalTables) {
	        kullanilabilirMasalar = totalTables;
	    }
	
	    vector<string> getYemekMenusu() const {
	        return yemekMenusu;
	    }
	    
	    void setYemekMenusu(const vector<string>& menu) {
	        yemekMenusu = menu;
	    }
	
	    vector<int> getYemekStoku() const {
	        return yemekStoku;
	    }
	    
	    void setYemekStoku(const vector<int>& stock) {
	        yemekStoku = stock;
	    }
	
	    vector<double> getYemekUcretleri() const {
	        return yemekUcretleri;
	    }
	    
	    void setYemekUcretleri(const vector<double>& prices) {
	        yemekUcretleri = prices;
	    }
	
	    vector<string> getIcecekMenusu() const {
	        return icecekMenusu;
	    }
	    
	    void setIcecekMenusu(const vector<string>& drinks) {
	        icecekMenusu = drinks;
	    }   
	    
	    vector<int> getIcecekStoku() const {
	        return icecekStoku;
	    }
	    
	    void setIcecekStoku(const vector<int>& drinksStock) {
	        icecekStoku = drinksStock;
	    }
	
	    vector<double> getIcecekUcretleri() const {
	        return icecekUcretleri;
	    }
	    
	    void setIcecekUcretleri(const vector<double>& prices) {
	        icecekUcretleri = prices;
	    }
	
	
	    void siparisAl() {
	        string yemekAdi, icecekAdi;
	        int yemekAdedi, icecekAdedi;
	
	        cout << "Sipari? vermek istedi?iniz yeme?in adyny girin: ";
	        cin >> yemekAdi;
	        vector<string>::iterator yemekIterator = find(yemekMenusu.begin(), yemekMenusu.end(), yemekAdi);
	        if (yemekIterator != yemekMenusu.end()) {
	            int yemekIndex = distance(yemekMenusu.begin(), yemekIterator);
	            cout << yemekAdi << " için adet girin: ";
	            cin >> yemekAdedi;
	            if (yemekStoku[yemekIndex] >= yemekAdedi) {
	                yemekStoku[yemekIndex] -= yemekAdedi;
	                cout << "Yemek sipari?i ba?aryyla alyndy!" << endl;
	                toplamSiparisler++; // statik de?iskeni güncelliyom
	
	                double yemekFiyat = yemekUcretleri[yemekIndex] * yemekAdedi;
	                cout << "Sipari? vermek istedi?iniz içece?in adyny girin: ";
	                cin >> icecekAdi;
	                vector<string>::iterator icecekIterator = find(icecekMenusu.begin(), icecekMenusu.end(), icecekAdi);
	                if (icecekIterator != icecekMenusu.end()) {
	                    int icecekIndex = distance(icecekMenusu.begin(), icecekIterator);
	                    cout << icecekAdi << " için adet girin: ";
	                    cin >> icecekAdedi;
	                    if (icecekStoku[icecekIndex] >= icecekAdedi) {
	                        icecekStoku[icecekIndex] -= icecekAdedi;
	                        cout << "Yçecek sipari?i ba?aryyla alyndy!" << endl;
	
	                        double icecekFiyat = icecekUcretleri[icecekIndex] * icecekAdedi;
	                        double toplamFiyat = yemekFiyat + icecekFiyat;
	                        cout << "\n\n\nFi?:" << endl;
	                        cout << yemekAdi << " x" << yemekAdedi << " = " << yemekFiyat << " TL" << endl;
	                        cout << icecekAdi << " x" << icecekAdedi << " = " << icecekFiyat << " TL" << endl;
	                        cout << "Toplam: " << toplamFiyat << " TL\n\n" << endl;
	                    } else {
	                        cout << "Üzgünüz, " << icecekAdi << " için yeterli stok yok." << endl;
	                    }
	                } else {
	                    cout << "Menüde böyle bir içecek bulunamady." << endl;
	                }
	            } else {
	                cout << "Üzgünüz, " << yemekAdi << " için yeterli stok yok." << endl;
	            }
	        } else {
	            cout << "Menüde böyle bir yemek bulunamady." << endl;
	        }
	    }
	
	    void menuyuGoruntule() const {
	        cout << "Yemek Menüsü:" << endl;
	        for (size_t i = 0; i < yemekMenusu.size(); ++i) {
	            cout << "- " << yemekMenusu[i] << " (" << yemekUcretleri[i] << " TL)" << endl;
	        }
	
	        cout << "Yçecek Menüsü:" << endl;
	        for (size_t i = 0; i < icecekMenusu.size(); ++i) {
	            cout << "- " << icecekMenusu[i] << " (" << icecekUcretleri[i] << " TL)" << endl;
	        }
	    }
	
	    void stoklariGoruntule() const {
	        cout << "Yemek Stoklary:" << endl;
	        for (size_t i = 0; i < yemekMenusu.size(); ++i) {
	            cout << "- " << yemekMenusu[i] << ": " << yemekStoku[i] << " adet (" << yemekUcretleri[i] << " TL)" << endl;
	        }
	
	        cout << "Yçecek Stoklary:" << endl;
	        for (size_t i = 0; i < icecekMenusu.size(); ++i) {
	            cout << "- " << icecekMenusu[i] << ": " << icecekStoku[i] << " adet (" << icecekUcretleri[i] << " TL)" << endl;
	        }
	    }
	
	    void masaRezervasyonuYap(int masaNumarasi) {
	        if (masaNumarasi >= 1 && masaNumarasi <= toplamMasalar) {
	            if (masaMevcutlugu[masaNumarasi - 1]) {
	                masaMevcutlugu[masaNumarasi - 1] = false;
	                kullanilabilirMasalar--;
	                cout << masaNumarasi << " numaraly masa ba?aryyla rezerve edildi!" << endl;
	            } else {
	                cout << masaNumarasi << " numaraly masa zaten rezerve edilmi?. Lütfen ba?ka bir masa seçin." << endl;
	            }
	        } else {
	            cout << "Geçersiz masa numarasy!" << endl;
	        }
	    }
	
	    void masaMevcutlugunuGoruntule() const {
	        cout << "Masa Mevcutlu?u:" << endl;
	        for (int i = 0; i < toplamMasalar; ++i) {
	            cout << "Masa " << (i + 1) << ": ";
	            if (masaMevcutlugu[i]) {
	                cout << "Müsait" << endl;
	            } else {
	                cout << "Rezerve Edilmi?" << endl;
	            }
	        }
	    }
	
	    void digerRestoranMenuyuGoruntule(const vector<RestoranYonetimSistemi>& digerRestoranlar) const {
	        for (const auto& restoran : digerRestoranlar) {
	            cout << "\n" << restoran.getRestoranIsmi() << " Menüsü:" << endl;
	            restoran.menuyuGoruntule();
	        }
	    }
	
	    static int getToplamSiparisler() {
	        return toplamSiparisler;
	    }
	
	    RestoranYonetimSistemi operator+(const RestoranYonetimSistemi& other) const {
	        vector<string> combinedYemekMenusu = yemekMenusu;
	        combinedYemekMenusu.insert(combinedYemekMenusu.end(), other.yemekMenusu.begin(), other.yemekMenusu.end());
	
	        vector<int> combinedYemekStoku = yemekStoku;
	        combinedYemekStoku.insert(combinedYemekStoku.end(), other.yemekStoku.begin(), other.yemekStoku.end());
	
	        vector<double> combinedYemekUcretleri = yemekUcretleri;
	        combinedYemekUcretleri.insert(combinedYemekUcretleri.end(), other.yemekUcretleri.begin(), other.yemekUcretleri.end());
	
	        vector<string> combinedIcecekMenusu = icecekMenusu;
	        combinedIcecekMenusu.insert(combinedIcecekMenusu.end(), other.icecekMenusu.begin(), other.icecekMenusu.end());
	
	        vector<int> combinedIcecekStoku = icecekStoku;
	        combinedIcecekStoku.insert(combinedIcecekStoku.end(), other.icecekStoku.begin(), other.icecekStoku.end());
	
	        vector<double> combinedIcecekUcretleri = icecekUcretleri;
	        combinedIcecekUcretleri.insert(combinedIcecekUcretleri.end(), other.icecekUcretleri.begin(), other.icecekUcretleri.end());
	
	        return RestoranYonetimSistemi(restoranIsmi + " & " + other.restoranIsmi, toplamMasalar + other.toplamMasalar, combinedYemekMenusu, combinedYemekStoku, 
	                                      combinedYemekUcretleri, combinedIcecekMenusu, combinedIcecekStoku, combinedIcecekUcretleri);
	    }
	
	    RestoranYonetimSistemi& operator++() {
	        toplamMasalar++;
	        kullanilabilirMasalar++;
	        masaMevcutlugu.push_back(true); // yeni eklenen masanyn müsait oldu?unu belirtir
	        return *this; // arty?tan sonra nesnenin kendisini döndürür 
	    }
	};
	
	int RestoranYonetimSistemi::toplamSiparisler = 0;
	
	int main() {
	    setlocale(LC_ALL, "Turkish");
	    
	    vector<string> yemekler = {"Pizza", "Makarna", "Sezar Salata", "Hamburger", "Yskender", "Beyti", "Adana Kebap", "Lahmacun"};
	    vector<int> yemekStok = {20, 20, 20, 20, 20, 20, 20, 20};
	    vector<double> yemekUcret = {30.0, 20.0, 25.0, 40.0, 50.0, 45.0, 40.0, 15.0};
	
	    vector<string> icecekler = {"Su", "Kola", "Iced Tea", "Ayran", "?algam"};
	    vector<int> icecekStok = {30, 30, 30, 30, 30};
	    vector<double> icecekUcret = {5.0, 10.0, 8.0, 6.0, 7.0};
	
	    RestoranYonetimSistemi restoran("Sapphire Bistro", 10, yemekler, yemekStok, yemekUcret, icecekler, icecekStok, icecekUcret);
	    RestoranYonetimSistemi baskaRestoran("Emerald Diner", 5, {"Tavuk", "Biftek","Kuru Fasulye"}, {10, 10, 10}, {30.0, 50.0, 70.0}, {"Meyve Suyu", "Soda", "Gazoz"}, {20, 20, 20}, {12.0, 7.0 ,15.0});
	    
	
	    
	
	    int secim;
	    while (secim != -1) {
	        cout << "\n" << restoran.getRestoranIsmi() << "'ya Ho?geldiniz!" << endl;
	        cout << "1. Menüyü Görüntüle" << endl;
	        cout << "2. Sipari? Ver" << endl;
	        cout << "3. Stoklary Görüntüle" << endl;
	        cout << "4. Masa Rezervasyonu Yap" << endl;
	        cout << "5. Masa Müsaitli?ini Görüntüle" << endl;
	        cout << "6. Toplam Sipari? Sayysyny Görüntüle" << endl;
	        cout << "7. Restoran Birle?tir" << endl;
	        cout << "8. Masa Sayysyny Arttyr" << endl;
	        cout << "Y?leminizi Seçiniz (Çyky? için -1 giriniz): ";
	        cin >> secim;
	
	        if (secim == 1) {
	            restoran.menuyuGoruntule();
	        } else if (secim == 2) {
	            restoran.siparisAl();
	        } else if (secim == 3) {
	            restoran.stoklariGoruntule();
	        } else if (secim == 4) {
	            int masaNumarasi;
	            cout << "Rezerve etmek istedi?iniz masa numarasyny girin (1-" << restoran.getToplamMasalar() << "): ";
	            cin >> masaNumarasi;
	            restoran.masaRezervasyonuYap(masaNumarasi);
	        } else if (secim == 5) {
	            restoran.masaMevcutlugunuGoruntule();
	        } else if (secim == 6) {
	            cout << "Toplam Sipari? Sayysy: " << RestoranYonetimSistemi::getToplamSiparisler() << endl;
	        } else if (secim == 7) {
	            RestoranYonetimSistemi yeniRestoran = restoran + baskaRestoran;
            yeniRestoran.menuyuGoruntule();
	        } else if (secim == 8) {
	            ++restoran;
	            cout << "Masa sayysy arttyryldy. Toplam masalar: " << restoran.getToplamMasalar() << endl;
	        } else if (secim == -1) {
	            cout << "Programdan çykylyyor..." << endl;
	        } else {
	            cout << "Geçersiz seçim! Lütfen tekrar deneyin." << endl;
	        }
	    }

	    return 0;
	}
