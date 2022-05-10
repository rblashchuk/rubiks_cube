#include <iostream>
#include <fstream>
#include "argparse/include/argparse/argparse.hpp"
#include "details.h"
#include "cube.h"

int main(int argc, char *argv[]) {

    Cube curr = Cube();

    argparse::ArgumentParser arg_parser("cube");

    arg_parser.add_argument("-n", "--new")
            .help("Creates new cube. Requires: Non-empty Aa-Zz string (cube name)")
            .nargs(1);

    arg_parser.add_argument("-l", "--load")
            .help("Loads previously saved cube. Requires: Non-empty Aa-Zz string (cube name)")
            .nargs(1);

    arg_parser.add_argument("--set_log")
            .help("Starts/stops logging current cube moves. Requires: \"on\" will start logging, \"off\" will stop.")
            .nargs(1);

    arg_parser.add_argument("-a", "--apply")
            .help("Applies sequence of moves to current cube. Requires: Non-empty string of moves (LRUDFBrLrRrUrDrFrB)")
            .nargs(1);

    arg_parser.add_argument("-r", "--rand")
            .help("Applies random move sequence to current cube. Requires: One integer - length of sequence")
            .nargs(1)
            .scan<'i', int>();

    arg_parser.add_argument("-out", "--output")
            .help("Prints position of current cube")
            .default_value(false)
            .implicit_value(true);

    arg_parser.add_argument("--solve")
            .help("Solves current cube and returns solving sequence")
            .default_value(false)
            .implicit_value(true);

    arg_parser.add_argument("-log")
            .help("Prints log of current cube.")
            .default_value(false)
            .implicit_value(true);


    arg_parser.add_argument("-cl", "--clear_log")
            .help("Clears log of current cube.")
            .default_value(false)
            .implicit_value(true);

    arg_parser.add_argument("-s", "--save")
            .help("Saves current cube to file. Requires: Non-empty Aa-Zz string (cube name)")
            .nargs(1);


    try {
        arg_parser.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err) {
        std::cerr << err.what() << std::endl;
        std::cerr << arg_parser;
        std::exit(1);
    }

    auto newcube = arg_parser.present<std::string>("--new");

    auto sequence = arg_parser.present<std::string>("--apply");

    auto loads = arg_parser.present<std::string>("--load");

    auto rand = arg_parser.present<int>("--rand");

    auto dumps = arg_parser.present<std::string>("--save");

    auto set_log = arg_parser.present<std::string>("--set_log");

    if (newcube) {
        std::string filename = newcube.value() + ".cub";
        curr.dump(filename);
        set_current(filename);
        std::cout << "New cube " << filename << " created.\n";
    }

    if (loads) {
        std::string filename = loads.value() + ".cub";
        curr.load(filename);
        set_current(filename);
        std::cout << "Cube " << filename << " loaded.\n";
    }

    if (set_log) {
        std::string filename = get_current();
        curr.load(filename);
        if (set_log.value() == "on") {
            curr.set_logging(true);
            std::cout << "Logging started.\n";
        }

        if (set_log.value() == "off") {
            curr.set_logging(false);
            std::cout << "Logging stopped.\n";
        }
        curr.dump(filename);
    }

    if (sequence) {
        std::string filename = get_current();
        curr.load(filename);
        curr.apply(sequence.value());
        std::cout << "Sequence " << sequence.value() << " applied.\n";
        curr.dump(filename);
    }

    if (rand) {
        std::string filename = get_current();
        curr.load(filename);
        std::string rand_seq = curr.rand_apply(rand.value());
        std::cout << "Random sequence of length " << rand.value() << " applied.\n(" << rand_seq << ")\n";
        curr.dump(filename);
    }

    if (arg_parser["--output"] == true) {
        std::string filename = get_current();
        curr.load(filename);
        std::cout << "Current state of cube:\n" << curr;
    }

    if (arg_parser["--clear_log"] == true) {
        std::string filename = get_current();
        curr.load(filename);
        curr.log = "";
        std::cout << "Log cleared.\n";
        curr.dump(filename);
    }

    if (arg_parser["--solve"] == true) {
        std::string filename = get_current();
        curr.load(filename);
        std::string solve = curr.solve_sequence();
        std::cout << "Solving sequence:\n" << solve << "\nCurrent state of cube:\n" << curr;
        curr.dump(filename);
    }

    if (arg_parser["-log"] == true) {
        std::string filename = get_current();
        curr.load(filename);
        std::cout << "Current log of cube:\n" << curr.log << "\n";
    }

    if (dumps) {
        std::string filename = dumps.value() + ".cub";
        curr.dump(filename);
        set_current(filename);
        std::cout << "Current cube saved as " << filename << ".\n";
    }


    return 0;
}


