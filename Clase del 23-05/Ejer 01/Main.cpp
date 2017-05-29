#include <iostream>
#include "SFML\Network.hpp"
#include "../json.hpp"
using namespace std;
using namespace sf;
using namespace nlohmann;
void main()
{
	cout << "El clima en Capital Federal es:" << endl;
	Http Dir;
	Dir.setHost("http://query.yahooapis.com");
	Http::Request Req;
	Req.setUri("/v1/public/yql?q=select%20*%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22Buenos%20Aires%2C%20arg%22)&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys");
	Http::Response Res = Dir.sendRequest(Req);
	json data = json::parse(Res.getBody().c_str());
	cout << data["query"]["results"]["channel"]["item"]["condition"]["text"];
	cin.get();
}