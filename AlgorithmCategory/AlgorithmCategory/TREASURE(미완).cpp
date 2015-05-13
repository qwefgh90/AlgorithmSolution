#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
https://algospot.com/judge/problem/read/TREASURE
*/

struct Point{
	double x;
	double y;
};
//�簢�� ���� üũ

//���� ������ ���ϴ� ��? 2���� ��ǥ�� �簢���� �� y 
//��ǥ ����� x,y
bool checkRectY(Point p1, Point p2, double rectx1, double rectx2, double y, Point& foundPoint){
	//�ٸ� ��� ����
	if (rectx2 < rectx1){
		double swap = rectx2;
		rectx2 = rectx1;
		rectx1 = swap;
	}
	if (p1.y <= p2.y){ //�ٱ����� ���
		if (p2.y < y)
			return false;
		if (y < p1.y) //������ ���
			return false;
	}
	else{
		if (p1.y < y)//�ٱ���
			return false;
		if (y < p2.y)//����
			return false;
	}
	
	//������ y�� ������ �ƴҶ�
	if ((p2.x - p1.x) != 0){
		double p = (p2.y - p1.y) / (p2.x - p1.x);
		double x = (y-p1.y) / p + p1.x;
		if (rectx1 <= x && x <= rectx2) {//�簢�� ���� ����?
			if (p1.x <= p2.x){ //���� ���� ����?
				if (p2.x >= x && p1.x <= x){
					foundPoint.x = x;
					foundPoint.y = y;
					return true;
				}
			}
			else{
				if (p2.x >= x && p1.x <= x){
					foundPoint.x = x;
					foundPoint.y = y;
					return true;
				}
			}
		}
		//������ y�� ����
	} else {
		double x = p2.x;
		if (rectx1 <= x && x <= rectx2) {
			foundPoint.x = x;
			foundPoint.y = y;
			return true;
		}
	}
	return false;
}


//���� ������ ���ϴ� ��? 2���� ��ǥ�� �簢���� x��
//��ǥ ���: x,y
bool checkRectX(Point p1, Point p2, double recty1, double recty2, double x, Point& foundPoint){
	//�ٸ� ��� ����
	if (recty2 < recty1){
		double swap = recty2;
		recty2 = recty1;
		recty1 = swap;
	}
	if (p1.x <= p2.x){ //�ٱ����� ���
		if (p2.x < x)
			return false;
		if (x < p1.x) //������ ���
			return false;
	}
	else{
		if (p1.x < x)//�ٱ���
			return false;
		if (x < p2.x)//����
			return false;
	}

	//������ x�� ������ �ƴҶ�
	if ((p2.y - p1.y) != 0){
		double p = (p2.y - p1.y) / (p2.x - p1.x);
		double y = p*(x - p2.x) + p2.y;
		if (recty1 <= y && y <= recty2) {//�簢�� ���� ����?
			if (p1.x <= p2.x){ //���� ���� ����?
				if (p2.y >= y && p1.y <= y){
					foundPoint.x = x;
					foundPoint.y = y;
					return true;
				}
			}
			else{
				if (p2.y >= y && p1.y <= y){
					foundPoint.x = x;
					foundPoint.y = y;
					return true;
				}
			}
		}
	}
	//������ x�� ����
	else {
		double y = p2.y;
		if (recty1 <= y && y <= recty2) {
			foundPoint.x = x;
			foundPoint.y = y;
			return true;
		}
	}
	return false;
}

enum DIR{
	LEFT,RIGHT,TOP,BOTTOM,NONE
};
//���� ����
DIR getDIR(Point target, Point point1, Point point2){
	if (point1.x == target.x && point2.y >= target.y && point1.y <= target.y){
		return LEFT;
	}
	else if (point2.x == target.x && point2.y >= target.y && point1.y <= target.y){
		return RIGHT;
	}
	else if (point2.y == target.y && point2.x > target.x && point1.x < target.x){
		return TOP;
	}
	else if (point1.y == target.y && point2.x > target.x && point1.x < target.x){
		return BOTTOM;
	}
	else{
		return NONE;
	}
}

//�������� �����ؾ��ϴ°�?
//������, ã����, �簢�� �� 2��
bool check(Point previous, Point result, Point point1, Point point2){
	DIR d1 = getDIR(previous, point1, point2);
	DIR d2 = getDIR(previous, point1, point2);
	if (d1 != d2){	//������ �����϶�
		return true;
	}
	return false;
}


//�������� �̿��Ͽ� �迭�� ���� ���Ǵ� �������� ����
void findRealPoint(Point* pointArray, int pointLen, Point* realPointArray, int &realPointLen, Point point1, Point point2){
	for (int i = 0; i < pointLen-1; i++){
		
		if (pointArray[i].x <= point2.x && pointArray[i].x >= point1.x && pointArray[i].y <= point2.y && pointArray[i].y >= point1.y
			&& pointArray[i+1].x <= point2.x && pointArray[i+1].x >= point1.x && pointArray[i+1].y <= point2.y && pointArray[i+1].y >= point1.y){
			//�簢�� �Ѵ� ����
			realPointArray[realPointLen] = pointArray[i];
			realPointLen++;
			realPointArray[realPointLen] = pointArray[i];
			realPointLen++;
			i++;
		}
		//�Ѵ� ���ΰ� �ƴ� ���
		else{
			Point lResult,rResult,tResult,bResult;
			Point r1, r2;
			r1.x = -1;
			r2.x = -1;
			bool left, right, top, bottom;
			//���� ����
			left = checkRectX(pointArray[i], pointArray[i + 1], point1.y, point2.y, point1.x, lResult);
			if (left){
				r1 = lResult;
			}
			//������ ����
			right = checkRectX(pointArray[i], pointArray[i + 1], point1.y, point2.y, point2.x, rResult);
			if (right){
				if (r1.x != -1){
					r2 = rResult;
				}
				else{
					r1 = rResult;
				}
			}
			//���� ����
			top = checkRectY(pointArray[i], pointArray[i + 1], point1.x, point2.x, point2.y, tResult);
			if (top){
				if (r1.x != -1){
					r2 = tResult;
				}
				else{
					r1 = tResult;
				}
			}
			//�Ʒ��� ����
			bottom = checkRectY(pointArray[i], pointArray[i + 1], point1.x, point2.x, point1.y, bResult);
			if (bottom){
				if (r1.x != -1){
					r2 = bResult;
				}
				else{
					r1 = bResult;
				}
			}
			if (r2.x == -1 && r1.x == -1){
				continue;
			}
			else if (r1.x != -1 && r2.x == -1){
				if (i == 0){
					
				}
			}else{
				
			}
			
		}
		//�簢�� �ܺ�
		//else if ((pointArray[i].x > point2.x || pointArray[i].x < point1.x) || (pointArray[i].y > point2.y || pointArray[i].y < point1.y)
		//	&& (pointArray[i+1].x > point2.x || pointArray[i+1].x < point1.x) || (pointArray[i+1].y > point2.y || pointArray[i+1].y < point1.y)){
		//	
		//}
		////�ϳ� ����, �ϳ� �ܺ�
		//else{
		//	
		//}
	}
}



int main(){

	Point point1;
	Point point2;
	//������ �� # 3 ~ 100
	int realPointLen = 0;
	Point realPointArray[100];
	int pointLen = 0;
	Point pointArray[100];
	int testcase = 0;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		scanf("%d %d %d %d %d", &point1.x, &point1.y, &point2.x, &point2.y, &pointLen);
		for (int j = 0; j < pointLen; j++){
			scanf("%d %d", pointArray[j].x, pointArray[j].y);
		}
		
	}

	return 0; 
}