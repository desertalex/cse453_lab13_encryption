/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Jacob Nelson"; }
   virtual std::string getCipherName()  { return "Beaufort"; }
   virtual std::string getEncryptAuth() { return "Jacob Nelson"; }
   virtual std::string getDecryptAuth() { return "Jacob Nelson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Singh, Simon (2000). The Code Book: The Science of Secrecy from Ancient Egypt to Quantum Cryptography. ISBN 0-385-49532-3.");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      str =  "Beaufort Cipher\n";
      str += "GET text to be encoded\n";
      str += "GET encryption key";
      str += "CREATE string of alpahabet\n";
      str += "CREATE encryption string by repeating encrpytion key.";
      str += "Encryption string determines transposition";
      str += "CREATE completed string";

      
      //Since the encryption is symmetric the encryption pseudocode 
      //also applies to decryption

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string ciphertext;
      std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      for(int i=0; i<plainText.size(); i++){
         char c0 = plainText[i];
         char c1 = password[i % password.size()];
         int start=0;
         for (int j=0l; j<26; j++){
            if(alphabet[j] == toupper(c0)){
                start=j;
                break;
            }
         }
         int offSet=0;
         for(int j=start; j<start+26; j++){
            int letter= j % 26;
            if(alphabet[letter] == toupper(c1)){
                break;
            }
            offSet++;
         }
        ciphertext += alphabet[offSet];
      }
      return ciphertext;
    }
    
  
   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText;
      std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      for(int i=0; i<cipherText.size(); i++){
         char c0 = cipherText[i];
         char c1 = password[i % password.size()];
         int start=0;
         for (int j=0l; j<26; j++){
            if(alphabet[j] == toupper(c0)){
                start=j;
                break;
            }
         }
         int offSet=0;
         for(int j=start; j<start+26; j++){
            int letter= j % 26;
            if(alphabet[letter] == toupper(c1)){
                break;
            }
            offSet++;
         }
         plainText += alphabet[offSet];
      }
      return plainText;
   }
};
    


#endif // CIPHER04_H