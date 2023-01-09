#include <Express.h>
using namespace EXPRESS_NAMESPACE;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

Express app;

void setup() {
  Serial.begin(115200);
  while (!Serial && !Serial.available()) {}

  Ethernet.begin(mac);

  // parse various different custom JSON types as JSON
  app.use(bodyParser::json);

  app.post("/", [](Request &req, Response &res) {
    res.send("Got a POST request");
  });

  app.listen(80, []() {
    Serial.print(F("Example app listening on port "));
    Serial.print(Ethernet.localIP());
    Serial.print(F(" "));
    Serial.println(app.port);
  });
}

void loop() {
  app.run();
}
