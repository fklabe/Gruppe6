/*
 * TASK1.H
 *
 *  Created on: 10.09.2019
 *      Author: aml
 */


/**
 *
 * \file TASK1.H
 *
 * \brief Contains namespace TASK1. Namespace TASK1 contains the implementation
 * of check sum calculation.
 *
 */



#ifndef TASK1_H_
#define TASK1_H_

#include "SHA256.H"
#include <string>

using namespace std;

/**
 *
 * \namespace TASK1
 *
 * \brief Contains the implementation
 * of check sum calculation.
 *
 */
namespace TASK1{



/**
 *
 * \var const string SYMBOLS
 *
 *	\brief This contains all possible characters a password can contain
 *
 */
const string SYMBOLS = "ABCDEFGHIJKLMNOPQRTSTUVWXYZabcdefghijklmopqrstuvwxyz0123456789"; //alphabet

/**
 *
 * \var const unsigned int MINIMAL_PWD_LENGTH
 *
 * \brief Defines the minimal length of a password
 *
 */
const unsigned int MINIMAL_PWD_LENGTH = 4; //ABCD

/**
 *
 * \class IBlackBox
 *
 *	\brief Interface class for password check classes.
 *
 */
class IBlackBox{
public:
	virtual string input(string strPwd) = 0;
	virtual string getSymbols() = 0; //Alphabet vom Server übernehmen
};


/**
 *
 * \class BlackBoxUnsafe
 *
 * \brief Implements a unsafe password checker where the
 * password is stored as plan text.
 *
 */
class BlackBoxUnsafe : public IBlackBox{
public:
				   BlackBoxUnsafe(int pwdLength, int symbSetSize);
	virtual string input(string strPwd);
			string getSymbols(); //Alphabet vom Server übernehmen

			string pwd_;

protected:
	string randomPwd(int pwdLength);
	char * charSymbArray_;
	int    lengthSymbArray_;
};

/**
 *
 * \class BlackBoxSafe
 *
 * \brief Implements a more safe password checker where only the
 * password's checksum is stored.
 *
 * Notice, implementation is not finished.
 *
 *
 */
 //Kindklasse von BlackBoxUnsafe
class BlackBoxSafe : public BlackBoxUnsafe{
	// \todo  Implementation of class BlackBoxSafe needs to be finalized.
	//Definition der Funktionen siehe TASK1.C
public:
	BlackBoxSafe(int pwdLength, int symbSetSize);
	string input(string strPwd);
};




/**
 *
 * \brief Simple demonstration of calculating
 * the check sum for a given string.
 *
 */
void demoTASK1_00();

/**
 *
 * \brief Simple demonstration of using the password checker.
 *
 */
void demoTASK1_01();

} // end namespace TASK1


#endif /* TASK1_H_ */
