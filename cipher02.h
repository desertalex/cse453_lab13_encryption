/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Nic Vane"; }
   virtual std::string getCipherName()  { return "Simple Substitution"; }
   virtual std::string getEncryptAuth() { return "Nic Vane"; }
   virtual std::string getDecryptAuth() { return "Nic Vane"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("http://practicalcryptography.com/ciphers/classical-era/simple-substitution/");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str =  "insert the encryption pseudocode\n";
      str += "\nstring allchars, cipherAlph";
      str += "\nfor i in password.length()";
      str += "\nfor j in allChars.length()";
      str += "\nif password[i] equals allChars[j]";
      str += "\nthen erase cipherAlph[j] and pushback password[i] to cipherAlph";
      str += "\nfor i in plainText.length()";
      str += "\nfor j in allChars.length()";
      str += "\nif plainText[i] equals allChars[j]";
      str += "\nthen pushback cipherAlph[j] to cipher";
      str += "\nreturn cipher";

      // The decrypt pseudocode
      str += "insert the decryption pseudocode\n";
      str += "\nstring allchars, plainText";
      str += "\nfor i in password.length()";
      str += "\nfor j in allChars.length()";
      str += "\nif password[i] equals allChars[j]";
      str += "\nthen erase cipherAlph[j] and pushback password[i] to cipherAlph";
      str += "\nfor i in cipher.length()";
      str += "\nfor j in allChars.length()";
      str += "\nif cipher[i] equals allChars[j]";
      str += "\nthen pushback cipherAlph[j] to plainText";
      str += "\nreturn plainText";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipher;
      std::string allChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()-_=+[{]}\\|;:\'\",<.>/?0123456789 ";
      std::string cipherAlph = "p0J$hACQ;Gqg*S46|&.i~[um{2X#ea\"7VW <Fy\'ln]=Mo`f)d3@8,Pxj!UHk(rc}:Zvst\\zDTwK%b5N9?Y_RBI1E+-L^O/>";

      // This generates the cipher alpabet to be used based off the key given
      for (int i = 0; i < password.length(); i++) {
         for (int j = 0; j < 95; j++) {
               if (password[i] == cipherAlph[j]) {
                  cipherAlph.erase(j, 1);
                  std::string temp(1, password[i]);
                  cipherAlph.insert(i, temp);
               }
         }
      }
      // This loops through the allChars alphabet to find the location of the plainText
      // letter to be switched with the character at the same location in allChars
      for (int i = 0; i < plainText.length(); i++) {
         for (int j = 0; j < 95; j++) {
               if (plainText[i] == allChars[j]) {
                  // if found add to cipher
                  cipher.push_back(cipherAlph[j]);
               }
         }
      }
      return cipher;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText;
      std::string allChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()-_=+[{]}\\|;:\'\",<.>/?0123456789 ";
      std::string cipherAlph = "p0J$hACQ;Gqg*S46|&.i~[um{2X#ea\"7VW <Fy\'ln]=Mo`f)d3@8,Pxj!UHk(rc}:Zvst\\zDTwK%b5N9?Y_RBI1E+-L^O/>";

      // This generates the cipher alpabet to be used based off the key given
      for (int i = 0; i < password.length(); i++) {
         for (int j = 0; j < 95; j++) {
               if (password[i] == cipherAlph[j]) {
                  cipherAlph.erase(j, 1);
                  std::string temp(1, password[i]);
                  cipherAlph.insert(i, temp);
               }
         }
      }

      // This loops through the cipher alphabet to find the location of the cipher
      // letter to be switched with the character at the same location in allChars
      for (int i = 0; i < cipherText.length(); i++) {
         for (int j = 0; j < 95; j++) {
               if (cipherText[i] == cipherAlph[j]) {
                  // if found add to plainText
                  plainText.push_back(allChars[j]);
               }
         }
      }
      return plainText;
   }
};

#endif // CIPHER02_H