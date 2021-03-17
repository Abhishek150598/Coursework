import java.sql.*;

public class LoginDAO {
	public static Boolean login(String username, String password, Connection con) {
		try {
			String query = "SELECT * FROM user WHERE uname = ? AND pass = ?";
			PreparedStatement preparedStatement = con.prepareStatement(query);
		    preparedStatement.setString(1, username);
		    preparedStatement.setString(2, password);
		    ResultSet rs = preparedStatement.executeQuery();
		    if(rs.next() == false) {
		    	return false;
		    }
		    return true;
		} catch(Exception e) { 
			System.out.println(e);
			return false;
		}
	}
}
