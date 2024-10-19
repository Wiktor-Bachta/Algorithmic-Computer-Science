from random import uniform, randint


def print_signals(signals, stations):
    signals = [[signal[1:] for signal in cell] for cell in signals]

    res = [" " for _ in range(len(signals))]

    for i, cell in enumerate(signals):
        if len(set(cell)) == 1:
            res[i] = cell[0]
        elif len(set(cell)) > 1:
            res[i] = "x"
    for station in stations:
        res[stations[station]["pos"]] = station

    print("".join(res))


def detect_collisions(signals):
    collisions = []
    for i in range(len(signals)):
        if len(signals[i]) > 1:
            collisions.append(i)
    return collisions


def handle_collisions(station, direction, stations):
    # Backoff for a random time before attempting to send again
    if stations[station][direction]["waiting"]:
        return
    stations[station][direction]["collisions"] += 1
    coll = stations[station][direction]["collisions"]
    r = randint(1, 2**coll)
    stations[station][direction]["waiting"] = r * 15
    stations[station][direction]["w2"] = (2**coll - r) * 15
    stations[station][direction]["sent"] = 0
    stations[station][direction]["sending"] = False


def propagate_signal(signals, stations, positions):
    new_signals = [[] for _ in range(30)]

    for i in range(len(signals)):
        if i in positions:
            for signal in signals[i]:
                if signal[1] == "x":
                    if signal[0] == "l":
                        handle_collisions(positions[i], "r", stations)
                    else:
                        handle_collisions(positions[i], "l", stations)
                if signal[1] != positions[i].lower():
                    if signal[1] != "x":
                        if signal[0] == "l" and i < len(signals) - 1 and signal not in signals[i+1]:
                            stations[positions[i]]["r"]["collisions"] = 0
                        elif signal[0] == "r" and i > 0 and signal not in signals[i-1]:
                            stations[positions[i]]["l"]["collisions"] = 0
                    signals[i].remove(signal)

    for i in range(len(signals)):
        unique = {signal[1:] for signal in signals[i]}
        if len(unique) > 1:
            signals[i] = ["lx", "rx"]

    for i in range(len(signals)):
        for signal in signals[i]:
            if signal[0] == "l":
                if i > 0:
                    new_signals[i - 1].append(signal)
            else:
                if i < len(signals) - 1:
                    new_signals[i + 1].append(signal)

    return new_signals


def main():
    cells = [" " for _ in range(30)]
    signals = [[] for _ in range(30)]
    positions = {0: "A", 15: "B", 29: "C"}
    stations = {"A": {"pos": 0, "l": {"sent": 0, "sending": False, "collisions": 0, "waiting": 0, "w2": 0}, "r": {"sent": 0, "sending": False, "collisions": 0, "waiting": 0, "w2": 0}},
                "B": {"pos": 15, "l": {"sent": 0, "sending": False, "collisions": 0, "waiting": 0, "w2": 0}, "r": {"sent": 0, "sending": False, "collisions": 0, "waiting": 0, "w2": 0}},
                "C": {"pos": 29, "l": {"sent": 0, "sending": False, "collisions": 0, "waiting": 0, "w2": 0}, "r": {"sent": 0, "sending": False, "collisions": 0, "waiting": 0, "w2": 0}}}
    steps = 0

    for station, properties in stations.items():
        cells[properties["pos"]] = station

    while (steps < 300):
        for station, v in stations.items():
            for dir in ("l", "r"):
                if v[dir]["waiting"]:
                    v[dir]["waiting"] -= 1
                    if not v[dir]["waiting"]:
                        v[dir]["sending"] = True
                    continue
                elif not v[dir]["sending"] and v[dir]["sent"] == 0:
                    if v[dir]["w2"]:
                        v[dir]["waiting"] = v[dir]["w2"]
                        v[dir]["w2"] = 0
                    elif (uniform(0, 1) > 1/2):
                        v[dir]["sending"] = True
                        signals[v["pos"]].append(dir + station.lower())
                        v[dir]["sent"] += 1
                else:
                    if v[dir]["sent"] == 4:
                        v[dir]["sending"] = False
                        v[dir]["waiting"] = 10
                        v[dir]["sent"] = 0
                    else:
                        signals[v["pos"]].append(dir + station.lower())
                        v[dir]["sent"] += 1

        signals = propagate_signal(signals, stations, positions)
        print_signals(signals, stations)
        steps += 1


if __name__ == "__main__":
    main()
