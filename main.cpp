#include "includes/libftcpp.hpp"
#include "src/Utils/Utils.hpp"

int	main(int, char **argv)
{
	Text		text(argv[1]);
	//std::string	tmp;

	(void)text;
	//text.addSeparators("LtSdFE");
	
	
	//text.addTmpSeparators(":");
	//text.showWords();
	//text.setTmpSeparatorStatus(true);
	//text.showWords();

	//text.setTmpSeparatorStatus(false);
	//text.showWords();
	
	std::cout << "Content : " << text.getContent() << std::endl;
	text.replace("t", "o");
	std::cout << "replaced Content : " << text.getContent() << std::endl;
	std::cout << "original Content : " << text.getOriginalContent() << std::endl;
	text.resetContent();
	text.replace("t", "o", 2);
	std::cout << std::endl;
	std::cout << "replaced Content : " << text.getContent() << std::endl;
	std::cout << "original Content : " << text.getOriginalContent() << std::endl;
	
	
	//text >> tmp;
	//std::cout << "TEST : " << text.hasFoundSeparator("L") << std::endl;


	//text.setMode(Text::Mode::REVERSE);
	//text.updateCursor(10);
	//while (1)
	//{
	//	text >> tmp;
	//	if (tmp.empty())
	//		break ;
	//	std::cout << "[" << tmp << "]" << std::endl;
	//	std::cout << text << std::endl;
	//}
	//text << "something to test here";
	//std::cout << text << std::endl;
	//std::cout << Utils::split(argv[1], "L") << std::endl;
	return (0);
}