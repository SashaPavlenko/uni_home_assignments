# Bus routes

`Buses` stores bus routes as `HashMap<Integer, ArrayList<String>>`: route number -> route name followed by its stops.

- `addBus(name, stops)` - adds a route and returns its number; a route with the same stops is rejected
- `sbusesForStop(stop)` / `nbusesForStop(stop)` - names / numbers of the routes that pass through a stop
- `stopsForBus(name)` - for every stop of a route, the other routes you can transfer to there
- `allBuses()` - all route names in alphabetical order

The demo in `main` uses stops of Rostov-on-Don.

```bash
javac -d out src/buses/Buses.java
java -cp out buses.Buses
```
