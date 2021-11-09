#include <functional>

namespace lucio {

	/*
	*	CallBack
	*	Use to call class member function from another class or Lambda.
	*
	*	Example:
	*	{
	*		auto funcCallBack = new CallBack<void>([]() {
	*			std::cout << "Hello World\n";
	*		});
	*
	*		funcCallBack->execute();
	*	}
	*
	*	Note: Can also be use whit std::bind"
	*/
	
	template <typename T, typename... Args>
	class CallBack {

		public:
			CallBack(std::function<T(Args...)> func) : _func(func) {};
			void execute(Args... args) const { _func(std::forward<Args>(args)...); };

		private:
			std::function<T(Args...)> _func;
	};

}