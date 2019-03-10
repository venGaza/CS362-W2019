import junit.framework.TestCase;

public class UrlValidatorTest extends TestCase {

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   // Run a series of both valid and invalid inputs on the isValid() method manually
   public void testManualTest() { 
      boolean result;
      String output, condition;  
      System.out.println("---- Starting Manual Tests ----\n");
      System.out.println("(Format: Component | Input | Expected Output | Test Result )\n");

      // Create new URLValidator object to test inputs
      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

      // Test valid schemes
      System.out.println("- Testing Valid Schemes (<scheme>www.google.com) -");
      String[] schemeValid = {"http://", "ftp://", "h3t://"};
      for (String scheme : schemeValid) {
         result = urlVal.isValid(String.format("%swww.google.com", scheme));
         condition = result ? "PASSED" : "FAILED";
         output = String.format("Scheme | %s | valid | %s", scheme, condition);
         System.out.println(output);
      }

      // Test invalid schemes
      System.out.println("\n- Testing Invalid Schemes (<scheme>www.google.com) -");
      String[] schemeInvalid = {"3ht://", "http:/", "http:", "http/", "://"};
      for (String scheme : schemeInvalid) {
         result = urlVal.isValid(String.format("%swww.google.com", scheme));
         condition = !result ? "PASSED" : "FAILED";
         output = String.format("Scheme | %s | invalid | %s", scheme, condition);
         System.out.println(output);
      }

      // Test valid authorities
      System.out.println("\n- Testing Valid Authorities (http://<authority>) -");
      String[] authorityValid = {"www.google.com", "google.com", "google.au", "go.au", "0.0.0.0", "255.com"};
      for (String authority : authorityValid) {
         result = urlVal.isValid(String.format("http://%s", authority));
         condition = result ? "PASSED" : "FAILED";
         output = String.format("Authority | %s | valid | %s", authority, condition);
         System.out.println(output);
      }

      // Test invalid authorities
      System.out.println("\n- Testing Invalid Authorities (http://<authority>) -");
      String[] authorityInvalid = {"256.256.256.256", "1.2.3.4.5", "1.2.3.4.", "1.2.3", ".1.2.3.4", "go.a",
                                    "go.a1a", "go.1aa", "aaa.", ".aaa", "aaa", ""};
      for (String authority : authorityInvalid) {
         result = urlVal.isValid(String.format("http://%s", authority));
         condition = !result ? "PASSED" : "FAILED";
         output = String.format("Authority | %s | invalid | %s", authority, condition);
         System.out.println(output);
      }

      // Test valid ports
      System.out.println("\n- Testing Valid Ports (http://www.google.com<port>) -");
      String[] portValid = {":80", ":65535", ":0", ""};
      for (String port : portValid) {
         result = urlVal.isValid(String.format("http://www.google.com%s", port));
         condition = result ? "PASSED" : "FAILED";
         output = String.format("Port | %s | valid | %s", port, condition);
         System.out.println(output);
      }

      // Test invalid ports
      System.out.println("\n- Testing Invalid Ports (http://www.google.com<port> -");
      String[] portInvalid = {":-1", ":65536", ":65a"};
      for (String port : portInvalid) {
         result = urlVal.isValid(String.format("http://www.google.com%s", port));
         condition = !result ? "PASSED" : "FAILED";
         output = String.format("Port | %s | invalid | %s", port, condition);
         System.out.println(output);
      }

      // Test valid paths
      System.out.println("\n- Testing Valid Paths (http://www.google.com/<path>) -");
      String[] pathValid = {"/test1", "/t123", "/$23", "/test1/", "/test1/file"};
      for (String path : pathValid) {
         result = urlVal.isValid(String.format("http://www.google.com%s", path));
         condition = result ? "PASSED" : "FAILED";
         output = String.format("Path | %s | valid | %s", path, condition);
         System.out.println(output);
      }

      // Test invalid paths
      System.out.println("\n- Testing Invalid Paths (http://www.google.com/<path>) -");
      String[] pathInvalid = {"/..", "/../", "/..//file", "/test1//file"};
      for (String path : pathInvalid) {
         result = urlVal.isValid(String.format("http://www.google.com%s", path));
         condition = !result ? "PASSED" : "FAILED";
         output = String.format("Path | %s | invalid | %s", path, condition);
         System.out.println(output);
      }
      
      // Test valid queries
      System.out.println("\n- Testing Valid Queries (http://www.google.com/<query>) -");
      String[] queryValid = {"?action=view", "?action=edit&mode=up", ""};
      for (String query : queryValid) {
         result = urlVal.isValid(String.format("http://www.google.com/%s", query));
         condition = result ? "PASSED" : "FAILED";
         output = String.format("Query | %s | valid | %s", query, condition);
         System.out.println(output);
      }

      /*
      // Test invalid queries 
      System.out.println("\n- Testing Invalid Queries -");
      String[] queryInvalid = {};
      for (String query : queryInvalid) {
         result = urlVal.isValid(String.format("http://www.google.com/%s", query));
         condition = !result ? "PASSED" : "FAILED";
         output = String.format("Query | %s | invalid | %s", query, condition);
         System.out.println(output);
      } */
      
      
      System.out.println("\n---- End of Manual Tests ----");
   }

   public void testIsValid() {
	   // You can use this function for programming based testing

   }
   
   
   public void testYourFirstPartition()
   {
	 // You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition() {
		 // You can use this function to implement your Second Partition testing	   

   }
   
   // Main Function
   public static void main(String[] argv) {
	   UrlValidatorTest fct = new UrlValidatorTest("url test");
      fct.testManualTest();
   }
}