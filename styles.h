#include <iostream>

namespace css{
	void setStyle(void)
	{
		std::cout << "<style>";
		std::cout << "body{font-family:sans-serif;background: repeating-radial-gradient(circle, purple, purple 10px,#4b026f 10px, #4b026f 20px);}";
		std::cout << ".form-container{border-radius:2px;box-shadow:1px 1px 1px 1px grey;width:300px;height:auto;margin:0 auto;padding:35px;color:white;background-color:#ff6868}";
		std::cout << "#submit-btn{border:none;background-color:#f9f381;padding:10px;margin-bottom:-20px;margin-top:20px;border-radius:2px;box-shadow:1px 1px 1px 1px grey;}";
		std::cout << "#submit-btn:hover{background-color:#f7ef51;}";
		std::cout << "#input-key{background-color:#717c76;margin-top:15px;border:none; height: 30px;color:white; font-size: 22px;}";
		std::cout << "#meaning-container{margin-top:20px;color:white;font-size:25px;height:auto;}";
		std::cout << "#meaning-text{'margin:20px;'}";
		std::cout << "</style>";
	}
}