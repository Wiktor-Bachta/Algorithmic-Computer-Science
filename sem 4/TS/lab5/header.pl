use HTTP::Daemon;
use HTTP::Status;  

my $d = HTTP::Daemon->new || die;
print "Please contact me at: ", $d->url, "\n";


while (my $c = $d->accept) {
    while (my $r = $c->get_request) {
        if ($r->method eq 'GET') {
            foreach ($r->header_field_names) {
                $c->send_response($_ . ":\n" . $r->header($_));
            }  
        }
        else {
            $c->send_error(RC_FORBIDDEN);
        }
    }
    $c->close;
    undef($c);
}
         
