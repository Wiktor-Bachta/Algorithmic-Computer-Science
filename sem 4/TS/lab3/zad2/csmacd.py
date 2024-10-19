from random import uniform


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


def propagate_signal(signals, stations, positions):
    new_signals = [[] for _ in range(30)]

    for i in range(len(signals)):
        if i in positions:
            for signal in signals[i]:
                if signal[1] != positions[i].lower():
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
    positions = {0: "A", 12: "B", 29: "C"}
    stations = {"A": {"pos": 0, "l": {"sent": 0, "sending": False, "collision": False, "waiting": 0}, "r": {"sent": 0, "sending": False, "collision": False, "waiting": 0}},
                "B": {"pos": 12, "l": {"sent": 0, "sending": False, "collision": False, "waiting": 0}, "r": {"sent": 0, "sending": False, "collision": False, "waiting": 0}},
                "C": {"pos": 29, "l": {"sent": 0, "sending": False, "collision": False, "waiting": 0}, "r": {"sent": 0, "sending": False, "collision": False, "waiting": 0}}}
    steps = 0

    for station, properties in stations.items():
        cells[properties["pos"]] = station

    while (steps < 20):
        for station, v in stations.items():
            for dir in ("l", "r"):
                if v[dir]["waiting"]:
                    v[dir]["waiting"] -= 1
                    continue
                elif not v[dir]["sending"] and v[dir]["sent"] == 0:
                    if (uniform(0, 1) > 1/2):
                        v[dir]["sending"] = True
                        signals[v["pos"]].append(dir + station.lower())
                        v[dir]["sent"] += 1
                else:
                    if v[dir]["sent"] == 4:
                        v[dir]["sending"] = False
                        v[dir]["sent"] = 0
                    else:
                        signals[v["pos"]].append(dir + station.lower())
                        v[dir]["sent"] += 1

        signals = propagate_signal(signals, stations, positions)
        print_signals(signals, stations)
        steps += 1


if __name__ == "__main__":
    main()
