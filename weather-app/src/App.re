type state = {weather: WeatherData.weather};

type action =
  | WeatherLoaded(WeatherData.weather);

let component = ReasonReact.reducerComponent("App");

let dummyWeather: WeatherData.weather = {
  summary: "Warm throughout the day",
  temp: 30.5,
};

let make = _children => {
  ...component,
  initialState: () => {weather: dummyWeather},
  reducer: (action, _prevState) =>
    switch (action) {
    | WeatherLoaded(newWeather) => ReasonReact.Update({weather: newWeather})
    },
  render: self =>
    <div className="App">
      <p> {ReasonReact.string(self.state.weather.summary)} </p>
    </div>,
};