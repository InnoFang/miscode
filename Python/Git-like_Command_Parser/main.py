import argparse
import sys

class FakeGit:
    def __init__(self):
        parser = argparse.ArgumentParser(
            description="Pretends to be git",
            usage="""git <command> [<args>]
The most commonly used git commands are: 
    commit      Record changes to the repository
    fetch       Download objects and refs from another repository
""")
        parser.add_argument("--version", action="version", version="%(prog)s version {}".format("0.1"))
        parser.add_argument("command", help="Subcommand to run")
        # parse_args defaults to [1:] for args, but you need to
        # exclude the rest of the args too, or validation will fail
        args = parser.parse_args(sys.argv[1:2])
        if not hasattr(self, args.command):
            print("Unrecongniized command")
            parser.print_help()
            exit(1)
        # use dispatch pattern to invoke method with same name
        getattr(self, args.command)()

    def commit(self):
        parser = argparse.ArgumentParser(
            description='Record changes to the repository')
        # prefixing the argument with -- menda it's optional
        parser.add_argument('--amend', action='store_true')
        # now that we're inside a subcommdan, ignore the first
        # TWO argvs, ie the command (git) and the subcommand (commit)
        args = parser.parse_args(sys.argv[2:])
        print("Running git commit, amend={}".format(args.amend))
    
    def fetch(self):
        parser = argparse.ArgumentParser(
            description='Download objects and refs from another repository')
        # NOT prefixing the argument with -- means it's not optional
        parser.add_argument('repository')
        args = parser.parse_args(sys.argv[2:])
        print("Running git fetch, repository={}".format(args.repository))
    
if __name__ == "__main__":
    FakeGit()
