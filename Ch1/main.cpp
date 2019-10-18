#include <Eigen/Dense>
#include <iostream>
#include "sophus/so3.hpp"

using namespace std;
using namespace Eigen;

int main(){
	
	Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(1,1,1)).toRotationMatrix();
	
	Quaterniond q_raw(R);

	Quaterniond q_w(1.0,0.005,0.01,0.015);
	
	Quaterniond q_new = q_raw*q_w;
	
	q_new.normalize();
	
	Matrix3d R_new_q = q_new.toRotationMatrix();

	//Sophus::SO3 SO3_q(R_new_q);
	
	cout<<"R is "<< R_new_q << "by q"<<endl;

	Vector3d so3_w(0.01,0.02,0.03);
	
	Sophus::SO3 SO3_w = Sophus::SO3::exp(so3_w);

	Sophus::SO3 SO3_R_raw(R);

	Sophus::SO3 SO3_R_new_lie_l = SO3_R_raw * SO3_w;
	
	cout<<"R is "<< SO3_R_new_lie_l.matrix() << "by Lie"<<endl;
	//cout<<"R is "<< SO3_R_new_lie_r.matrix() << "by Lie"<<endl;

}
