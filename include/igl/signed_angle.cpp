#include "signed_angle.h"
#include "PI.h"
#include <cmath>

template <
  typename DerivedA,
  typename DerivedB,
  typename DerivedP>
IGL_INLINE typename DerivedA::Scalar igl::signed_angle(
  const Eigen::MatrixBase<DerivedA> & A,
  const Eigen::MatrixBase<DerivedB> & B,
  const Eigen::MatrixBase<DerivedP> & P)
{
  typedef typename DerivedA::Scalar SType;
  // Gather vectors to source and destination
  SType o2A[2];
  SType o2B[2];
  // and lengths
  SType o2Al = 0;
  SType o2Bl = 0;
  for(int i = 0;i<2;i++)
  {
    o2A[i] = P(i) - A(i);
    o2B[i] = P(i) - B(i);
    o2Al += o2A[i]*o2A[i];
    o2Bl += o2B[i]*o2B[i];
  }
  o2Al = sqrt(o2Al);
  o2Bl = sqrt(o2Bl);
  // Normalize
  for(int i = 0;i<2;i++)
  {
    // Matlab crashes on NaN
    if(o2Al!=0)
    {
      o2A[i] /= o2Al;
    }
    if(o2Bl!=0)
    {
      o2B[i] /= o2Bl;
    }
  }
  return
    -atan2(o2B[0]*o2A[1]-o2B[1]*o2A[0],o2B[0]*o2A[0]+o2B[1]*o2A[1])/
    (2.*igl::PI);
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false>::Scalar igl::signed_angle<Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false>, Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 2, 0, -1, 2> const, 1, 2, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>::Scalar igl::signed_angle<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Matrix<double, 1, 2, 1, 1, 2> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 1, 2, 1, 1, 2> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>::Scalar igl::signed_angle<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Matrix<double, 1, 3, 1, 1, 3> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 1, 3, 1, 1, 3> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1> const, 1, -1, false>::Scalar igl::signed_angle<Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Matrix<float, 1, 3, 1, 1, 3> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Matrix<float, 1, 3, 1, 1, 3> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>::Scalar igl::signed_angle<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Matrix<float, 1, 3, 1, 1, 3> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Matrix<float, 1, 3, 1, 1, 3> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>::Scalar igl::signed_angle<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>, Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>, Eigen::Matrix<float, 1, 3, 1, 1, 3> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false> > const&, Eigen::MatrixBase<Eigen::Matrix<float, 1, 3, 1, 1, 3> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>::Scalar igl::signed_angle<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>::Scalar igl::signed_angle<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Matrix<double, 3, 1, 0, 3, 1> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 3, 1, 0, 3, 1> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>::Scalar igl::signed_angle<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Matrix<double, 1, 3, 1, 1, 3> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 1, 3, 1, 1, 3> > const&);
// generated by autoexplicit.sh
template Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>::Scalar igl::signed_angle<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false>, Eigen::Matrix<double, 1, 2, 1, 1, 2> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<double, -1, -1, 0, -1, -1> const, 1, -1, false> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 1, 2, 1, 1, 2> > const&);
template Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>::Scalar igl::signed_angle<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>, Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false>, Eigen::Matrix<float, 1, 2, 1, 1, 2> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 0, -1, 3> const, 1, 3, false> > const&, Eigen::MatrixBase<Eigen::Matrix<float, 1, 2, 1, 1, 2> > const&);
template Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>::Scalar igl::signed_angle<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true>, Eigen::Matrix<float, 1, 2, 1, 1, 2> >(Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Block<Eigen::Matrix<float, -1, 3, 1, -1, 3> const, 1, 3, true> > const&, Eigen::MatrixBase<Eigen::Matrix<float, 1, 2, 1, 1, 2> > const&);
#ifdef WIN32
template float igl::signed_angle<class Eigen::Block<class Eigen::Matrix<float,-1,3,1,-1,3> const ,1,3,1>,class Eigen::Block<class Eigen::Matrix<float,-1,3,1,-1,3> const ,1,3,1>,class Eigen::Matrix<float,1,2,1,1,2> >(class Eigen::MatrixBase<class Eigen::Block<class Eigen::Matrix<float,-1,3,1,-1,3> const ,1,3,1> > const &,class Eigen::MatrixBase<class Eigen::Block<class Eigen::Matrix<float,-1,3,1,-1,3> const ,1,3,1> > const &,class Eigen::MatrixBase<class Eigen::Matrix<float,1,2,1,1,2> > const &);
template float igl::signed_angle<class Eigen::Block<class Eigen::Matrix<float,-1,3,0,-1,3> const ,1,3,0>,class Eigen::Block<class Eigen::Matrix<float,-1,3,0,-1,3> const ,1,3,0>,class Eigen::Matrix<float,1,2,1,1,2> >(class Eigen::MatrixBase<class Eigen::Block<class Eigen::Matrix<float,-1,3,0,-1,3> const ,1,3,0> > const &,class Eigen::MatrixBase<class Eigen::Block<class Eigen::Matrix<float,-1,3,0,-1,3> const ,1,3,0> > const &,class Eigen::MatrixBase<class Eigen::Matrix<float,1,2,1,1,2> > const &);
#endif
#endif
