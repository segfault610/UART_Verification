#!/usr/bin/perl
use strict;
use warnings;

# Path to the transcript file
my $transcript = "../sim/transcript";

# If transcript doesn't exist in ../sim, look in current directory
if (! -e $transcript) {
    $transcript = "transcript";
}

my $pass = 0;
my $fail = 0;
my $fh; # Declare it here so it's in scope for the whole script

if (!open($fh, '<', $transcript)) {
    print "ERROR: Could not find simulation log at $transcript\n";
    exit;
}

while (my $line = <$fh>) {
    # We look for the [PASS] string
    if ($line =~ /\[PASS\]/) {
        $pass++;
    }
    # Check for fails, mismatches, or timeouts
    if ($line =~ /\[FAIL\]/ || $line =~ /MISMATCH/ || $line =~ /TIMEOUT/) {
        $fail++;
    }
}

close($fh);

print "\n=================================\n";
print "      UART VERIFICATION REPORT   \n";
print "=================================\n";
print "LOG FILE            : $transcript\n";
print "SUCCESSFUL TRANSFERS: $pass\n";
print "FAILED TRANSFERS    : $fail\n";
print "STATUS              : ", ($fail == 0 && $pass > 0) ? "PASSED" : "FAILED", "\n";
print "=================================\n\n";

