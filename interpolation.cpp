//given data points (t, y) and a set of x values to interpolate for
//return the derivative of the algorithm

for(int i = 0; i<x.size();i++){ //for every evaluation point
  Eigen::VectorXd p(y); //p is a copy of y
  Eigen::VectorXd dp = Eigen::VectorXd::Zero(y.size()); // zeros since the derivatives y values is zero
  //implement aitken neville algo
    for(int right = 0; right<y.size(); right++){
      for(int left = right-1; left>=0; left--){
        dp(left) = (p(left+1)+(dp(left+1)*(x(i)-t(left)))-(p(left)+dp(left)*(x(i)-t(right))))/(t(right)-t(left));
        p(left) = ((x(i)-t(left))*p(left+1)-((x(i)-t(right))*p(left)))/(t(right)-t(left)); //y(right) = y(left+1)
      }
    }
    ret(i) = dp(0);
  }
