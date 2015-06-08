/***********************************************************
	statutil.cpp -- ���ϗʃf�[�^
***********************************************************/
#include "statutil.h"

StatUtil::StatUtil()
{
	rows = 0;
	cols = 0;
}

StatUtil::~StatUtil()
{
	
}

/*
double getnum(FILE *datafile)
{
	double x;
	char *rest, s[83];

	do {
		if (fscanf(datafile, "%81s%*[^ \t\n]", s) != 1)
			return READERROR;
	} while (strchr("0123456789+-.", s[0]) == NULL);
	if (s[0] == '.' && s[1] == '\0') return MISSING;
	s[81] = '?';
	s[82] = '\0';
	x = strtod(s, &rest);
	if (errno == 0 && *rest == '\0' && fabs(x) <= 0.97E+37)
		return x;
	errno = 0;
	return READERROR;
}
*/

int StatUtil::read_data(char* filename)
{
	unsigned long missings = 0;
	double t;

	std::ifstream ifs(filename);
	if( !ifs ) {
		std::cerr << "�f�[�^�t�@�C�����ǂ߂܂���" << std::endl;
		return 999;
	}
	
	std::string buf, strrow, strcol;
	char *rest;
	
	getline(ifs, buf);
	std::istringstream stream(buf);
	getline(stream, strrow, ',' );
	getline(stream, strcol);
	rows = atoi(strrow.c_str());
	cols = atoi(strcol.c_str());
	if (rows <= 0 || rows > INT_MAX || cols <= 0 || cols > INT_MAX) {
		std::cerr << "�s���E�񐔂��ǂ߂܂���" << std::endl;
		return 999;
	}
	Matrix tmp(rows, cols);
	
	std::string str;
	int r = 0;
	int c = 0;
	int err = 0;
	while( getline( ifs, str ) ){
		std::string token;
		std::stringstream ss, ss2;
		std::istringstream stream( str );
		c = 0;
 
		while( getline( stream, token, ',' ) ) {
		
			if (err) {  
				tmp(r, c)= READERROR;
				c++;
				continue;  
			}
			t = strtod(token.c_str(), &rest);
			if (errno == 0 && *rest == '\0' && fabs(t) <= 0.97E+37) {
				tmp(r, c) = t;
			} else if (readerror(t)){
				tmp(r, c) = READERROR;
				std::cerr << "�Ǎ��݃G���[" << r + 1 << "," << c + 1 << std::endl;
				err = 2;
			} else {
				tmp(r, c) = MISSING;
				missings++;
			}
			c++;
			if (c > cols) {
				std::cerr << (r + 1) << "�s�ڂ͗񐔃I�[�o�[�ł�" << std::endl;
				break;
			}
		}
		if (c < cols) {
			std::cerr << (r + 1) << "�s�ڂ͗񐔕s��" << std::endl;
			for (int i = c; i < cols; i++) {
				tmp(r, i) = READERROR;
				missings++;
			}
		}
		r++;
		if (r > rows) {
			std::cerr <<  "�s���I�[�o�[�ł�" << std::endl;
			break;
		}
	}
	if (r < rows) {
		std::cerr <<  "�s���s��" << std::endl;
		for (int i = r; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				tmp(i, j) = READERROR;
				missings++;
			}
		}
	}
	
	mat = tmp;
	std::cerr <<  "�Ǎ��ݏI�� (�����l " << missings << " ��)" << std::endl;
	return err | (missings != 0);
}
