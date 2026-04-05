
// using namespace std;

void Quizz() {

  // (a) Define the number of observed decays:
  // Bplus = 120
  // Bminus = 100
  int Bplus = 120;
  int Bminus =100;
  double A_CP=(Bplus -Bminus ) / (Bplus + Bminus );

  // (b) Calculate the CP asymmetry:

  std::cout<<"A_CP=(Bpius - Bminus ) /(Bplus + Bminus )"<<std::endl;
  // A_CP = (Bplus - Bminus) / (Bplus + Bminus)



  // (c) Print the CP asymmetry



  // (d) Using if / else:
  if(abs( A_CP ) > 0.05)

    {
      std::cout<<"CP vilation observed"<<std::endl;
    }

  else{std::cout<<"No significant CP violation"<<std::endl;
  }
  // print "CP violation observed" if |A_CP| > 0.05
  // otherwise print "No significant CP violation"
