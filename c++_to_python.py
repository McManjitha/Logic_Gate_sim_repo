import subprocess


def test_no_io():
    '''
    Run a process that takes no input and produces no output
    '''
    ## Shell=False helps the process terminate
    process = subprocess.Popen("./my_graph", shell=False)

    ## Get exit codes
    out, err = process.communicate()
    errcode = process.returncode

    process.kill()
    process.terminate()

test_no_io()